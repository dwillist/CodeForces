#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

char temp[123];
string s;

int VK_count(string str){
  int to_return = 0;
  for(int i = 1; i < str.size(); ++i){
    if(str[i-1] == 'V' && str[i] == 'K'){
      to_return++;
    }
  }
  return to_return;
}

int main(){
  scanf("%s",temp);
  s = temp;
  int max_count = VK_count(s);
  for(int i = 0; i < s.size(); ++i){
    string new_s = s;
    if(new_s[i] == 'V'){
      new_s[i] = 'K';
    }
    else{
      new_s[i] = 'V';
    }
    max_count = max(max_count,VK_count(new_s));
  }
  printf("%d\n",max_count);
}
