#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

vector<int> A[150123];
bool V[150123] = {0};

bool all_visited(int node,int size){
  if(A[node].size() != size){
    return false;
  }
  for(int i = 0; i < A[node].size(); ++i){
    int next = A[node][i];
    if(!V[next]){return false;}
  }
  return true;
}

bool is_clique(int start){
  V[start] = true;
  for(int i = 0; i < A[start].size(); i++){
    V[A[start][i]] = true;
  }
  for(int j = 0; j < A[start].size();j++){
    int next = A[start][j];
    if(!all_visited(next,A[start].size())){return false;}
  }
  return true;
}

int main(){
  int n,m;
  int a,b;
  scanf("%d %d\n",&n,&m);
  for(int i = 0; i < m; ++i){
    scanf("%d %d",&a,&b);
    A[a].push_back(b);
    A[b].push_back(a);
  }
  for(int i = 1; i <=n; ++i){
    if(!V[i] && !is_clique(i)){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
