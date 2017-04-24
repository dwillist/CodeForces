#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;
int n;
// RICK -> 0
// MORTY -> 1
vector<int> v[2];
int dps[7123][2] = {0};
int deg[7123][2];


// -1 is LOSE
// 1 is WIN
// 0 is Unassigned / Loop
void dp_solve(int i,int j){
  for(auto k:v[!j]){
    int p = (n-k+i)%n; //pos for opponent that can reach this position
    if(dps[p][!j]) continue;// already has a value so we can ignore
    else if(dps[i][j] == -1){
      dps[p][!j] = 1;
      dp_solve(p,!j);
    }
    else{ // dps[i][j] == 1
      --deg[p][!j];
      if(deg[p][!j] == 0){
        dps[p][!j] = -1;
        dp_solve(p,!j);
      }
    }
  }
}


int main(){
  int k,temp;
  scanf("%d",&n);
  for(int i = 0; i < 2; ++i){
    scanf("%d",&k);
    for(int j = 0; j < k; ++j){
      scanf("%d",&temp);
      v[i].push_back(temp);
    }
  }
  for(int i = 0; i < n; ++i){
    deg[i][0] = v[0].size();
    deg[i][1] = v[1].size();
  }
  // now all deg are set
  dps[0][1] = -1;
  dps[0][0] = -1;
  dp_solve(0,1);
  dp_solve(0,0);
  for(int j = 0; j < 2; ++j){
    for(int l = 1; l < n; ++l){
      if(dps[l][j] == 1){
        printf("Win ");
      }

      else if(dps[l][j] == -1){
        printf("Lose ");
      }
      else{
        printf("Loop ");
      }
    }
    printf("\n");
  }

}
