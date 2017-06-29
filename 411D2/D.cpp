#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

long long R = 1000000007;

char c_arr[1234567];
string s;

int main(){
  scanf("%s",c_arr);
  string s = c_arr;
  int n = s.size();
  long long current_sum = 0;
  long long total_sum = 0;
  for(int i = s.size()-1; i >= 0; --i){
    if(s[i] == 'a'){
      total_sum = (total_sum + current_sum) % R;
      current_sum = (current_sum*2)%R;
    }
    else{
      current_sum = (current_sum+1)%R;
    }
  }
  printf("%lld\n",total_sum);
}
