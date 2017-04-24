#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

string int_to_name(int i){
  string to_return;
  while(i){
    to_return += (i%26) + 'a';
    i = i/26;
  }
  to_return[0] -= 32;
  return to_return;
}

char s[10];

int main(){
  int n,k;
  vector<int> names;
  scanf("%d %d",&n,&k);
  names.resize(n);
  for(int i = 0; i < n;++i){
    names[i] = i+1;
  }
  int index = 1;
  int lo = 1;
  for(int i = 0; i <= n-k; ++i){
    scanf("%s",s);
    string s_str = s;
    if(s_str == "NO" ){
      names[i+k-1] = names[i];
    }
  }
  for(int i = 0; i < names.size(); ++i){
    string to_print = int_to_name(names[i]);
    printf("%s ",to_print.c_str());
  }
  printf("\n");
}
