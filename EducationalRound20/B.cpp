#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int max_dist = 1234567;

vector<long long> V;
vector<int> D;
int n;


void leftScan(int pos){
  int value = 0;
  while(D[pos] >= value && pos > -1){
    D[pos] = value;
    value++;
    pos--;
  }
}

void rightScan(int pos){
  int value = 0;
  while(D[pos] >= value && pos < n){
    D[pos] = value;
    value++;
    pos++;
  }
}

int main(){
  scanf("%d",&n);
  D.resize(n,max_dist);
  V.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%d",&V[i]);
    if(V[i] == 0){
      D[i] = 0;
    }
  }
  for(int j = 0; j < n; ++j){
    if(V[j] == 0){
      leftScan(j);
      rightScan(j);
    }
  }
  for(int k = 0; k < n; ++ k){
    printf("%d ",D[k]);
  }
  printf("\n");
}
