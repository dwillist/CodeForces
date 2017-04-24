#include <vector>
#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;

int main(){
  int a,b,c,d,temp;
  scanf("%d %d\n",&a,&b);
  scanf("%d %d\n",&c,&d);
  set<int> M;
  for(int i = 0; i < 200; ++i){
    M.insert(b + i*a);
  }
  for(int j = 0; j < 200; ++j){
    if(M.find(d + j*c) != M.end()){
      printf("%d\n",d+j*c);
      return 0;
    }
  }
  printf("-1\n");
}
