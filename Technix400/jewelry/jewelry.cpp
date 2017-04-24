#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

bool is_prime(int k,vector<int> &primes){
  for(int i = 0; i < primes.size(); ++i){
    if(k % primes[i] == 0){
      return false;
    }
  }
  primes.push_back(k);
  return true;
}

int main(){
  int n;
  scanf("%d",&n);
  if(n < 3){
    printf("1\n");
  }
  else{
    printf("2\n");
  }
  vector<int> primes;
  for(int i = 2; i <= n+1; ++i){
    if(primes.empty()){
      primes.push_back(i);
      printf("1 ");
    }
    else{
      is_prime(i,primes) ? printf("1 ") : printf("2 ");
    }
  }
}
