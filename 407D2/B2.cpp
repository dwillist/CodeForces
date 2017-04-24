#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

int main(){
  long long b,q,l,m,temp;
  set<long long> V;
  scanf("%lld %lld %lld %lld",&b,&q,&l,&m);
  for(long long i =0; i < m; ++i){
    scanf("%lld",&temp);
    V.insert(temp);
  }
  int total = 0;
  pair<long,long> prev = make_pair(12345678910,12345678910);
  while(abs(b) <= l){
    if( b == prev.second){
      if(V.find(b) == V.end()){
      printf("inf\n");
      return 0;
      }
      else{
        break;
      }
    }
    else if(b == prev.first){
      // then we basically guarentee -1 as q
      if(V.find(prev.first) != V.end() && V.find(prev.second) != V.end()){
        break;
      }
      else{
        printf("inf\n");
        return 0;
      }
    }
    if(V.find(b) == V.end()){
      total++;
    }
    prev.first = prev.second;
    prev.second = b;
    b*=q;
  }
  printf("%d\n",total);
}
