#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

char temp[123456];
string s;
string t = "";
string u = "";
map<char,int> M;

int main(){
  scanf("%s",temp);
  s = temp;
  for(int i = 0;i < s.size(); ++i){
    if(M.find(s[i]) == M.end()){
      M[s[i]] = 0;
    }
    M[s[i]]++; // might need to spiff this up if default behavior doesn't work
    //printf("count of %c is %d\n",s[i],M[s[i]]);
  }
  for(int j = 0; j < s.size(); ++j){
    map<char,int>::iterator iter = M.begin();
    if(s[j] <= iter->first){
      //printf("appending %c with count %d\n",s[j],M[s[j]]);
      u.append(1,s[j]);
    }
    else{
      t.append(1,s[j]);
    }
    M[s[j]]--;
    if(M[s[j]] <= 0){
      //printf("erasing %c\n",s[j]);
      M.erase(s[j]);
    }
  }
  reverse(t.begin(),t.end());
  u = u + t;
  printf("%s\n",u.c_str());
}
