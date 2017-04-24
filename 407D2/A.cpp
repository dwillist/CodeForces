#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
  long long n,k,wi,T;
  T = 0;
  scanf("%I64d %I64d",&n,&k);
  for(int i = 0; i<n; ++i){
    scanf("%I64d",&wi);
    //int to_add = (wi + k-1)/k;
    //printf("%d to_add\n",to_add);
    T += (wi + (k-1))/k;
  }
  printf("%I64d\n",(T +1)/2);
}
