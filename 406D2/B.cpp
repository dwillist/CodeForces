#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

bool cancel(vector<int> & v,int k){
  set<int> S;
  for(int i=0; i < k; ++i){
    //printf("%d at %d ",v[i],i);
    if(S.find(v[i]) != S.end()){
      //printf("\n");
      return false;
    }
    S.insert(-1*v[i]);
  }
  //printf("\n");
  return true;
}

int main(){
  int n,m,k;
  scanf("%d %d",&n,&m);
  vector<int> G;
  G.resize(100000);
  for(int i = 0; i < m; ++i){
    scanf("%d",&k);
    for(int j =0;j < k; ++j){
      scanf("%d",&G[j]);
      //printf("scanned %d \n",G[j]);
    }
    if(cancel(G,k)){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
}
