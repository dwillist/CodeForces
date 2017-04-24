#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;

int main(){
  int x1,x2,y1,y2;
  scanf("%d",&n);
  printf("YES\n");
  for(int i = 0; i < n; ++i){
    scanf("%d %d %d %d\n",&x1,&y1,&x2,&y2);
    int to_print = abs(x1%2) + 2*abs(y1%2) + 1;
    printf("%d\n",to_print);
  }
}
