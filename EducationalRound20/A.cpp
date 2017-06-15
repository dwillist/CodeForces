#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

vector< vector< int > > V;
int n,k;


int main(){
  scanf("%d %d",&n,&k);
  if( k > n*n){
    printf("-1\n");
    return 0;
  }
  V.resize(n);
  for(int i = 0; i < n; ++i){
    V[i].resize(n,0);
  }
  int largest_open_diagonal = 0;
  for(int i = 0; i < n; ++i){
    for(int j = i; j < n; ++j){
      if(k <= 1){
        goto endloop;
      }
      else if(i == j){
        V[i][j] = 1;
        k--;
        largest_open_diagonal = i+1;
      }
      else{
          V[i][j] = 1;
          V[j][i] = 1;
          k = k-2;
      }
    }
  }
  endloop:
  if(k){
    V[largest_open_diagonal][largest_open_diagonal] = 1;
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      printf("%d ",V[i][j]);
    }
    printf("\n");
  }
}
