#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;


long M = 1000000007;
char A[234567];
long F[200000];
long O[234567];
long C[234567];

long nCk(long n,long k){
  return (F[n]/(F[n-k] * F[k])) % M ;
}

int main(){
  F[0] = 1;
  for(int i = 1; i < 200000; ++i){
    F[i] = (F[i-1] * i)%M;
  }
  scanf("%s",A);
  string a_str = A;
  O[0] = (int)(a_str[0] == '(');
  for(int i = 1; i < a_str.size();++i){
    O[i] = O[i-1] + (a_str[i] == '(');
  }
  C[a_str.size()-1] = (int)(a_str[a_str.size()-1] == ')');
  for(int j = a_str.size()-2; j>=0; j--){
    C[j] = C[j+1] + (a_str[j] == ')');
  }
  long to_return = 0;
  for(int k = 0; k < a_str.size(); ++k){
    if(a_str[k] == '('){
      printf("k at %d\n",k);
      long to_add = nCk(O[k] + C[k] -1, O[k]-1)%M;
      printf("adding %ld from n: %ld and k: %ld\n",to_add, O[k] + C[k]-1,C[k]);
      to_return = (to_add + to_return)%M;
      //to_return = (to_return + nCk(O[k] + C[k] -1, O[k]-1))%M;
    }
  }
  printf("%ld\n",to_return);
}
