#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

char t1[123];
char t2[123];
string s1;
string s2;

bool possible(string s,string y){
  for(int i= 0; i < s.size(); ++i){
    if(s[i] < y[i]){
      return false;
    }
  }
  return true;
}

int main(){
  scanf("%s",t1);
  scanf("%s",t2);
  s1 = t1;
  s2 = t2;
  if(possible(s1,s2)){
    printf("%s\n",s2.c_str());
  }
  else{
    printf("-1\n");
  }

}
