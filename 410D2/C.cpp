#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> V;
int n;

int gcd(int a,int b){
  while(b > 0){
    int temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

int main(){
  scanf("%d",&n);
  V.resize(n);
  int current_gcd = 0;
  for(int i = 0; i < n; ++i){
    scanf("%d",&V[i]);
    current_gcd = gcd(V[i],current_gcd);
  }
  int to_print = 0;
  int current_count = 0;
  printf("YES\n");
  if(current_gcd > 1){
    printf("0\n");
  }
  else{
    for(int j = 0; j < n; ++j){
      if(V[j] %2 == 1){
        current_count++;
      }
      else{
        to_print += current_count/2 + (2 * (current_count%2));
        current_count = 0;
      }
    }
    to_print += current_count/2 + (2 * (current_count%2));
    printf("%d\n",to_print);
  }
}
