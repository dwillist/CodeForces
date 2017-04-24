#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n,m,k;

int main(){
  int min_dist = 100;
  int temp;
  scanf("%d %d %d\n",&n,&m,&k);
  for(int i = 0; i < n; ++i){
    scanf("%d ",&temp);
    if(k >= temp && temp != 0){ // we can buy
      min_dist = min(min_dist,abs(i+1 - m));
    }
  }
  printf("%d\n",min_dist*10);
}
