// this is a solution attempt that uses a few different tranformations to get
// an instance of 2SAT that is then solvable.

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> A[200002];
// array of vectors of size
vector<int> doors = vector<int>(100000,0);
vector<int> switches = vector<int>(100000,-1);
vector<int> component = vector<int>(200001,-1);

void dfs(int v,int current_component){
  component[v] = current_component;
  for(int i = 0; i < A[v].size(); ++i){
    int to = A[v][i];
    if(component[to] == -1){
      dfs(to,current_component);
    }
  }
}

int main(){
  int n,m,k,temp,z;
  scanf("%d %d\n",&n,&m);
  for(int i = 0; i < n; ++i){
    scanf("%d",&doors[i]);
  }
  for(int j = 0;j < m; ++j){
    scanf("%d",&k);
    for(int l = 0; l < k; ++l){
      scanf("%d",&z);
      if(switches[z-1] == -1){
        switches[z-1] = j;
      }
      else{
        // we add edges to our graph
        int s1 = 2 * (j);
        int s2 = switches[z-1] * 2;
        if(doors[z-1] == 0){ // door is closed
          A[s1].push_back(s2+1);
          A[s2].push_back(s1+1);
          A[s1+1].push_back(s2);
          A[s2+1].push_back(s1);
        }
        else{ // door is open
          A[s1].push_back(s2);
          A[s1+1].push_back(s2+1);
          A[s2].push_back(s1);
          A[s2+1].push_back(s1+1);
        }
      }
    }
  }
  // graph should now be built
  // now just use dfs to check if any 2*j. 2*j +1 are in the same component
  int component_label = 0;
  for(int i = 0; i <= 2*n+1;++i){
    if(component[i] == -1){
      dfs(i,component_label++);
    }
  }
  for(int j = 0; j <= n;++j){
    if(component[2*j] == component[2*j+1]  && component[2*j]!= -1){
      printf("NO\n");
      exit(0);
    }
  }
  printf("YES\n");
  exit(0);
}
