#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
  int n;
  vector<int> V;
  scanf("%d\n",&n);
  V.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%d ",&V[i]);
  }
  for(int j = 0; j < n/2; ++j){
    if(j%2 == 0)
      swap(V[j],V[n-j-1]);
  }
  for(int k = 0; k < n; ++k){
    printf("%d ",V[k]);
  }
  printf("\n");
}
