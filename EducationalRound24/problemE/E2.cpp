#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

// here we are going to use the two pointer method

// idea is to prime factor all numbers of A in nlogn,
// then use 2 pointer method to iterate through and test if range is divisable by k
const int MAX = 100001;
int n,k;
vector<long long> A;
vector< map<int,int> > A_facs;
long long F = 0;

map<int,int> factorize(int k_val){
  map<int,int> to_return;
  while(k_val != 1){
    for(int i = 2; i <= k_val; ++i){
      if(k_val %i ==0){
        to_return[i]++;
        k_val /=i;
        break;
      }
    }
  }
  return to_return;
}

map<int,int> fac_other(int to_fac,map<int,int> & fac_list){
  map<int,int> to_return;
  for( auto i : fac_list){
    while(to_fac % i.first == 0){
      to_return[i.first]++;
      to_fac /= i.first;
    }
  }
  return to_return;
}

bool covered(map<int,int> & M){
  for(auto & i: M){
    if(i.second > 0){
      return false;
    }
  }
  return true;
}

int main(){
  scanf("%d %d",&n,&k);
  if(k == 1){
    long long np = n;
    printf("%lld\n",(np*(np+1))/2);
    return 0;
  }
  map<int,int> k_fac = factorize(k);
  A.resize(n);
  A_facs.resize(n,map<int,int>());
  for(int i = 0; i < n; ++i){
    scanf("%d",&A[i]);
    A_facs[i] = fac_other(A[i],k_fac);
  }

  int left = 0;
  int right = 0;
  map<int,int> factor_cover = k_fac;
  while((right < n && left < n) || covered(factor_cover)){
    if(left > n){
      break;
    }
    if(covered(factor_cover) && left <= right){
      //printf("covered indicies %d %d\n",left,right);
      //printf("%d added\n",n-right+1);
      F += n-right+1;
      for(auto i: factor_cover){
        factor_cover[i.first] += A_facs[left][i.first];
      }
      left++;
    }
    else{
      //printf("non covered indicies %d %d\n",left,right);
      for(auto i: factor_cover){
        factor_cover[i.first] -= A_facs[right][i.first];
      }
      right++;
    }
  }
  printf("%lld\n",F);
}
