#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

string edit(string S){
  string to_return = "";
  bool appended = false;
  bool zero_seen = false;
  for(int i = 0; i < S.size(); ++i){
    zero_seen = zero_seen || S[i] == '0';
    if(appended && S[i] != 'n'){
      to_return.push_back(S[i]);
    }
    else if(!appended && S[i] != '0' && S[i] != 'n'){
      appended = true;
      to_return.push_back(S[i]);
    }
  }
  if( to_return == "" && zero_seen){
    to_return.push_back('0');
  }
  return to_return;
}

// returns the longer of the two strings or "" if no string exits
void parse_string(string S,vector<int> &remove1, vector<int> remove2){
  string S1 = "";
  string S2 = "";
  if(remove1.size()){
    S1 = S;
    int last = remove1.size() -1;
    S1[remove1[last]] = 'n';
    S1 = edit(S1);
  }
  if(remove2.size()>1){
    S2 = S;
    int last = remove2.size()-1;
    S2[remove2[last]] = 'n';
    S2[remove2[last-1]] = 'n';
    S2 = edit(S2);
  }
  if(S1 == "" && S2 == ""){
    printf("-1\n");
    return;
  }
  if(S1.size() > S2.size()){
     printf("%s\n",S1.c_str());
     return;
  }
  printf("%s\n",S2.c_str());
}

string edit(string & str){
  bool printed = false;
  bool edited = false;
  string to_return = "";
  for(int j = 0; j < str.size(); ++j){
    if(str[j] == 'n'){
      edited = true;
    }
    if(printed && str[j] != 'n')
      to_return.push_back(str[j]);
    else if(str[j] != 'n' && str[j] != '0'){
      to_return.push_back(str[j]);
      printed = true;
    }
    else if (j == str.size() -1 && !printed && str[j] == '0'){
      to_return.push_back(str[j]);
      printed = true;
    }
  }
  if(edited) return to_return;
  return "";
}

char s[123456];
string S;
int total;
vector<int> V[3];

int main(){
  scanf("%s",s);
  S = s;
  total = 0;
  for(int i =0; i < S.size(); ++i){
    int cur_mod = (S[i] - '0')%3;
    V[cur_mod].push_back(i);
    total = (total + cur_mod)%3;
  }
  if (total == 0){
    printf("%s\n",S.c_str());
    return 0;
  }
  if(total == 1){
    parse_string(S,V[1],V[2]);
  }
  else{
    parse_string(S,V[2],V[1]);
  }
}
