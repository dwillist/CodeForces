#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>

using namespace std;

// watch out B[0] is the RIGHTMOST bit
bitset<63> B;
long long n;
int maxbit;
char str[123456];

int calc_max(long long n){
  n = n+1;
  int to_set = 0;
  while(n){
    to_set++;
    n= n/2;
  }
  return to_set-1;
}

bool Left(bitset<63> & BS){
  if(BS[0]){return false;}
  for(int i = 1; i < maxbit;i++){
    if(BS[i]){
      BS[i] = false;
      BS[i-1] = true;
      return true;
    }
  }
  return false;
}
bool Right(bitset<63> & BS){
  if(BS[0]){return false;}
  for(int i = 1; i < maxbit; ++i){
    if(BS[i]){
      BS[i-1] = true;
      return true;
    }
  }
  return false;
}

bool Parent(bitset<63> & BS){
  for(int i = 0; i < maxbit-1; ++i){
    if(BS[i] && !BS[i+1]){
      BS[i] = false;
      BS[i+1] = true;
      return true;
    }
    else if(BS[i] && BS[i+1]){
      BS[i] = false;
      return true;
    }
  }
  return false;
}

int main(){
  long long q,start;
  scanf("%I64d %I64d",&n,&q);
  maxbit = calc_max(n);
  for(long long i =0; i < q; ++i){
    scanf("%I64d",&start);
    scanf("%s",str);
    string s = str;
    B = bitset<63>(start);
    for(int i = 0; i < s.size(); ++i){
      if( s[i] == 'U'){
        Parent(B);
      }
      else if(s[i] == 'R'){
        Right(B);
      }
      else{ //(s[i] == 'L')
        Left(B);
      }
      //printf(" now at: %llu\n",B.to_ullong());
    }
    printf("%I64u\n",B.to_ullong());
  }
}
