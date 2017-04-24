#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int V[123456];

int main(){
  int n;
  scanf("%d\n",&n);
  for(int i = 0; i < n; ++i){
    scanf("%d",&V[i]);
  }
  sort(V,V+n);
  pair<int,int> s = make_pair(V[0],V[1]);
  for(int i  = 2; i < n; ++i){
    if( s.first+s.second > V[i]){
      printf("YES\n");
      return 0;
    }
    s.first = s.second;
    s.second = V[i];
  }
  printf("NO\n");
  return 0;
}
