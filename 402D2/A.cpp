#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<int> B(5,0);
vector<int> A(5,0);

int main(){
  int n,temp;
  scanf("%d",&n);
    for(int i = 0; i < n; ++i){
      scanf("%d",&temp);
      A[--temp]++;
    }
    for(int i = 0; i < n; ++i){
      scanf("%d",&temp);
      B[--temp]++;
  }
  int to_print = 0;
  for(int j = 0; j < 5; ++j){
    if((B[j] + A[j]) % 2 == 1){
      printf("-1\n");
      return 0;
    }
    else{
      to_print += (abs(A[j] - B[j])/2);
    }
  }
  printf("%d\n",to_print/2);
  return 0;
}
