#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

bool isNeg(int n){
  return n < 0;
}

int main(){
  int min_odd = 12345;
  int n,temp;
  int sum = 0;
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    scanf("%d",&temp);
    if(temp > 0){
      sum += temp;
    }
    if(abs(temp) % 2 == 1 && abs(temp) < min_odd){
      min_odd = abs(temp);
    }
  }
  if(sum % 2 == 0){
    sum = sum - min_odd;
  }
  printf("%d\n",sum);
}
