#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
  int m,b;
  scanf("%d %d\n",&m,&b);
  int years = 0;
  while(m<=b){
    m*=3;
    b*=2;
    years++;
  }
  printf("%d\n",years);
}
