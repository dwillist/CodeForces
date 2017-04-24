// an alternative way to appoach this problem is as a graph coloring problem
// color a graph such that all verticies on connected by -1 are the opposite color
// and all verticies connected by 1 are the same color
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
vector<int> A[100000];
vector<int> W[100000];
int coloring[100000];
int rooms[100000];
int switches[100000];

bool dfs(int v,int color){
  coloring[v] = color;
  bool flag = true;
  for(int i = 0; i < A[v].size(); ++i){
    int to = A[v][i];
    int to_weight = W[v][i];
    int next_color = to_weight == color;
    if(flag == false){
      return false;
    }
    else if(coloring[to] == -1){
      flag = dfs(to,next_color);
    }
    else{
      flag = (coloring[to] == next_color);
    }
  }
  return flag;
}

int main(){
  fill(coloring,coloring+100000,-1);
  fill(switches,switches+100000,-1);
  int n,k,m,temp;
  scanf("%d %d",&n,&m);
  bool all_open = true;
  for(int i = 0; i < n; ++i){
    scanf("%d",rooms+i); // 1 denotes open 0 closed
    if(rooms[i] == 0){
      all_open= false;
    }
  }
  if(all_open){
    printf("YES\n");
    return 0;
  }
  for(int i = 0; i < m; ++i){
    scanf("%d",&k);
    for(int j = 0; j < k; ++j){
      scanf("%d",&temp);
      temp--;
      if(switches[temp] == -1){
        switches[temp] = i;
      }
      else{
        A[i].push_back(switches[temp]);
        W[i].push_back(rooms[temp]);
        A[switches[temp]].push_back(i);
        W[switches[temp]].push_back(rooms[temp]);
      }
    }
  }
  // now graph should be complete
  for(int i = 0; i < m; ++i){
    if(coloring[i] == -1 && !dfs(i,1)){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
