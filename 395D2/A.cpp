#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
  int n,m,z;
  scanf("%d",&n);
  scanf("%d",&m);
  scanf("%d",&z);
  //scanf("%d %d %d\n",&n,&m,&z);
  //printf("scanned\n");
  int killed = 0;
  for(int i = 1; i <= z; ++i){
    if(i%m == 0 && i%n==0){
      killed++;
    }
  }
  printf("%d\n",killed);
}
