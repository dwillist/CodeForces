#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

long long n,k;
vector<long long> V;

long long seq_sum(long long i){
  return i*(i+1)/2;
}

vector<long long> factorize(long long n){
  vector<long long> to_return;
  for(long long i = 1; i < ((long long)sqrt(n))+1; ++i){
    if (n % i == 0){
      to_return.push_back(i);
      to_return.push_back(n/i);
    }
  }
  sort(to_return.begin(),to_return.end());
  return to_return;
}

int main(){
  scanf("%lld %lld",&n,&k);
  //printf("%lld seq_sum\n",seq_sum(k));
  if(k > n || seq_sum(k) > n || seq_sum(k) < k){ // need to do some bound checking...
    printf("-1\n");
    return 0;
  }
  //else
  V = factorize(n);
  long long index = 0;
  while(index < V.size() && seq_sum(k) <= n/V[index]){
    index++;
  }
  index--;
  long long rem = n/V[index];
  for(long long j = 1; j < k; ++j){
    printf("%lld ",j*V[index]);
    rem -= j;
  }
  printf("%lld\n",rem*V[index]);
}
