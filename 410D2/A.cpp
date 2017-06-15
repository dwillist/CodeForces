#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int diffPal(string &str){
  int s = 0;
  int e = str.size()-1;
  int to_return = 0;
  while(s < e){
    if(str[s] != str[e]){
      to_return++;
    }
    s++;
    e--;
  }
  return to_return;
}

int main(){
  string result;
  char s[20];
  scanf("%s",s);
  result  =s;
  if(diffPal(result) == 1){
    printf("YES\n");
  }
  else if(diffPal(result) == 0 && (result.size() % 2 == 1)){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }
}
