#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;
vector<ll> V;
vector<ll> D;
vector<ll> R;
int n;

ll go(int i){
  if(i+2 < n-1){
    R[i] = max(D[i],D[i] - D[i+1] + R[i+2]);
  }
  else{
    R[i] = D[i];
  }
  return R[i];
}

int main(){
  scanf("%d",&n);
  V.resize(n);
  D.resize(n-1);
  R.resize(n-1);
  for(int i=0; i < n; ++i){
    scanf("%I64d",&V[i]);
    if( i > 0){
      D[i-1] = abs(V[i] - V[i-1]);
    }
  }
  ll to_print = 0;
  for(int j = n-2; j >= 0; j--){
    to_print = max(to_print,go(j));
    //printf("R[%d]: %d\n",j,R[j]);
    //printf("D[%d]: %d\n",j,D[j]);
  }
  printf("%I64d\n",to_print);
}
