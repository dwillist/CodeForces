#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string.h> // needed for memset;

using namespace std;

vector<long long> A; // this represents our tree
vector<long long> V; // this will hold our values
int k,n,N;

long long combine(long long rng1,long long rng2){
  //printf("variables %lld,%lld,%d\n",rng1,rng2,k);
  return (rng1*rng2) % k;
}

long long identity(){
  return 1;
}

long long buildSegmentTree(int node,int lo,int hi){
  //printf("node value :%d, %d,%d\n",node,lo,hi);
  if(lo == hi){
    A[node] = V[lo]%k;
  }
  else{
    int mid = (hi-lo)/2 + lo;
    long long p1 = buildSegmentTree(node*2,lo,mid) %k;
    long long p2 = buildSegmentTree(node*2+1,mid+1,hi) %k;
    A[node] = combine(p1,p2);
  }
  return A[node];
}

 long long querySegment(int query_lo,int query_hi,int rng_lo,int rng_hi,int node){
   //printf("query: %d,%d rng: %d,%d node %d\n",query_lo,query_hi,rng_lo,rng_hi,node);
   int mid = (rng_hi-rng_lo)/2 + rng_lo;
   if(node == 0){
     throw "ValueError()";
   }
   if(rng_lo > query_hi || rng_hi < query_lo){
     return identity();
   }
   else if(query_lo <= rng_lo && query_hi >= rng_hi){
     return A[node];
   }
   else{
     long long p1 = querySegment(query_lo,query_hi,rng_lo,mid,node*2);
     long long p2 = querySegment(query_lo,query_hi,mid+1,rng_hi,node*2 +1);
     return combine(p1,p2);
   }
 }

 long long q_interface(int q_lo,int q_hi){
   return querySegment(q_lo,q_hi,1,n,1);
 }

int get_vec_size(int n){
   int to_return = 1;
   while(to_return < n){
     to_return = to_return << 1;
   }
   return 2*to_return;
 }

int main(){
  scanf("%d %d",&n,&k);
  N = get_vec_size(n);
  V.resize(0);
  A.resize(0);
  V.resize(n+1,0);
  A.resize(N+1,0);
  for(int i = 1; i <= n; ++i){
    scanf("%lld",&V[i]);
  }
  buildSegmentTree(1,1,n);
  int left_ptr = 1;
  int right_ptr = 1;
  long long total = 0;
  while(right_ptr <= n){
    //printf("left %d , right %d\n",left_ptr,right_ptr);
    if(q_interface(left_ptr,right_ptr) == 0){
      //printf("valid range\n");
      total += n-right_ptr+1;
      if(left_ptr < right_ptr){
        left_ptr++;
      }
      else{
        right_ptr++;
        left_ptr++;
      }
    }
    else{
      right_ptr++;
    }
  }
  printf("%lld\n",total);
}
