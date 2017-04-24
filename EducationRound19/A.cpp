#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int n,k;

vector<int> k_factorize(int n,int k){
  int sq = (sqrt(n) + 1);
  vector<int> to_return;
  for(int i = 2; i <= sq && to_return.size() < k-1; ++i){
      while(n % i == 0 && to_return.size() < k-1){
        to_return.push_back(i);
        n = n/i;
      }
  }
  if(n > 1){
    to_return.push_back(n);
  }
  return to_return;
}

int main(){
  scanf("%d",&n);
  scanf("%d",&k);
  vector<int> to_print = k_factorize(n,k);
  if(to_print.size() == k){
    for(int i = 0; i < to_print.size(); ++i){
      printf("%d ",to_print[i]);
    }
    printf("\n");
  }
  else{
    printf("-1\n");
  }
}
