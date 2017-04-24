#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<int> v[200010];
vector<int> c = vector<int>(200010,-1);

void assignColors(int node,int prev_node,int p1,int p2){
  //printf("node %d\n",node);
  int color_start = 1;
  for(int i = 0; i < v[node].size(); ++i){
    int next = v[node][i];
    if(next != prev_node){
      //printf("next node %d\n",next);
      for(int k = color_start; k < v[node].size() + 2; ++k){
        if(k!= p1 && k != p2 && c[next] == -1){
          c[next] = k;
          color_start = k+1;
          break;
        }
      }
      assignColors(next,node,c[next],c[node]);
    }
  }
  //printf("end\n");
}

int main(){
  int n,a,b;
  scanf("%d\n",&n);
  for(int i = 0; i <n-1; ++i){
    scanf("%d %d\n",&a,&b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  // now lets color
  int max_size = 0;
  for(int i = 1; i < 200001; ++i){
    if(v[i].size() > max_size){
      max_size = v[i].size();
    }
  }
  printf("%d\n",max_size+1);
  c[1] = 1;
  assignColors(1,-1,1,-1);
  for(int i = 1; i <= n; ++i){
    printf("%d ",c[i]);
  }
  printf("\n");
}
