#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n,m,k;
vector<int> holes;

int main(){
  int bone_pos = 1;
  int s1,s2;
  scanf("%d %d %d\n",&n,&m,&k);
  holes.resize(m);
  for(int i = 0; i < m; ++i){
    scanf("%d",&holes[i]);
  }
  sort(holes.begin(),holes.end());
  for(int j = 0;j < k; ++j){
    scanf("%d %d\n",&s1,&s2);
    if(binary_search(holes.begin(),holes.end(),bone_pos)){
      printf("%d\n",bone_pos);
      return 0;
    }
    else if(bone_pos == s1){
      bone_pos = s2;
    }
    else if(bone_pos == s2){
      bone_pos = s1;
    }
  }
  printf("%d\n",bone_pos);
}
