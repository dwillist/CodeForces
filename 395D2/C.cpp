#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> V[123456];
int C[123456];
int n;

bool same_color(int current);
bool rec_same(int current,int parent);

int initial_scan(int current,int parent){
  for(auto i:V[current]){
    if( i != parent ){
      if(C[i] != C[current]){
        if(same_color(i)){
          return i;
        }
        else if(same_color(current)){
          return current;
        }
        else{
          return 0;
        }
      }
      int k = initial_scan(i,current);
      if(k == 0){
        return 0;
      }
      else if(k != 1){
        return k;
      }
    }
  }
  return 1;
}

bool same_color(int current){
  // wraps actual recursive function
  bool to_return = true;
  for(auto i: V[current]){
    to_return = rec_same(i,current);
    if(!to_return){return false;}
  }
  return true;
}

bool rec_same(int current,int parent){
  for(auto i: V[current]){
    if(i != parent){
      if(C[i] != C[current]){
        return false;
      }
      if(!rec_same(i,current)){
        return false;
      }
    }
  }
  return true;
}

int main(){
  scanf("%d\n",&n);
  int s,e;
  for(int i = 0; i < n-1; ++i){
    scanf("%d %d\n",&s,&e);
    V[e].push_back(s);
    V[s].push_back(e);
  }
  for(int i = 1; i<=n; ++i){
    scanf("%d ",&C[i]);
  }
  int result = initial_scan(1,-1);
  if(result){
    printf("YES\n%d\n",result);
  }
  else{
    printf("NO\n");
  }
}
