#include <cstdio>
#include <cstdlib>

long long n,k;

int main(){
  scanf("%lld",&n);
  scanf("%lld",&k);
  long long l = (n/2) / (k+1);
  long long d = l;
  long long c = l*k;
  long long none = n - d - c;
  printf("%lld %lld %lld\n",d,c,none);
}
