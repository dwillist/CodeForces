#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

void solve(string num_string,int k){
  int zero_count = 0;
  int index = num_string.size()-1;
  while(zero_count < k && index >= 0){
    if(num_string[index] == '0'){zero_count++;}
    index--;
  }
  if(zero_count == k){
    printf("%d\n",(int)(num_string.size() -1 - index) - zero_count);
    return;
  }
  else{
    printf("%d\n",(int)num_string.size()-1);
  }
}

string int_to_s(int i){
  stringstream s;
  s << i;
  return s.str();
}

int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  string n_str = int_to_s(n);
  solve(n_str,k);
}
