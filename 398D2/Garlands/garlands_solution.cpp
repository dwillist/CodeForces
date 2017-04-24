#include <vector>
#include <cstdio>
#include <stdlib.h>

using namespace std;

vector<int> g[1000000];
int val[1000000];
vector<int> nums;
int sum = 0;

bool dfs(int node_index,int parent){
  bool flag = false;
  for(int i = 0; i < g[node_index].size(); ++i){
    if(g[node_index][i] != parent){
      if(dfs(g[node_index][i],node_index)){
        flag = true;
      }
      val[node_index] += val[g[node_index][i]]; // add next node value to this one
    }
  }
  // now dfs has run its course we can do logic with flag
  if(parent != -1){
    if((!flag && val[node_index] == sum/3) || (flag && val[node_index] == 2*sum/3)){
      flag = true;
      nums.push_back(node_index);
      if(nums.size() > 1){
        printf("%d %d\n",nums[0]+1,nums[1]+1);
        exit(0);// quit program
      }
    }
  }
  return flag;
}


int main(){
  int n,temp,par,root;
  scanf("%d\n",&n);
  for(int i =0 ;i < n; ++i){
    scanf("%d %d",&par,&temp);
    if(par != 0){
      g[i].push_back(par-1);
      g[par-1].push_back(i);
    }
    else{
      root = i;
    }
    val[i] = temp;
    sum += val[i];
  }
  if(sum % 3 == 0){
    dfs(root,-1);
  }
  printf("-1\n");
}
