#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int A[26];
long long MOD = 1000000000 + 7;
long long M[1234];
int Split[1234];
int maxlen = 1;
char s[1234];

int to_index(char c){
  return c -'a';
}

int main(){
  int n;
  scanf("%d\n",&n);
  scanf("%s\n",s);
  string str = s;
  for(int k = 0; k < 26; ++k){
    scanf("%d ",&A[k]);
  }
  M[0] = 1;
  Split[0] = 1;
  for(int i = 1; i < n; ++i){
    Split[i] = n;
    //string current = "";
    int len = 0;
    int size_bound = 12345;
    for(int j = i; j >= 0; j--){
      //current.push_back(s[j]);
      len++;
      int index = to_index(s[j]);
      size_bound = min(size_bound,A[index]);
      if(size_bound >= len){
        maxlen = max(maxlen,len);
        if( j > 0){
          M[i] = (M[i] + M[j-1])%MOD;
          Split[i] = min(Split[i],Split[j-1] + 1);
        }
        else{
          M[i] = (M[i] + 1)%MOD;
          Split[i] = 1;
        }
      }
      else{
        break;
      }
    }
  }
  printf("%I64d\n%d\n%d\n",M[n-1],maxlen,Split[n-1]);
}
