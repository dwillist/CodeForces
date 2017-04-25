#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int counts[26] = {0};
char temp[123456];
string s,t,u;

int to_index(char c){
  return c - 'a';
}

int main(){
  scanf("%s",temp);
  s = temp;
  int index_ptr = 0;
  for(int i =0; i < s.size(); ++i){
    int index = to_index(s[i]);
    counts[index]++;
  }
  for(int j = 0; j < s.size(); ++j){
    while(counts[index_ptr] == 0){index_ptr++;} //increment index pointer
    int current_index = to_index(s[j]);
    if(t.size() && to_index(t[t.size()-1]) <= index_ptr){
      //printf("one\n");
      u += t[t.size()-1];
      t.pop_back();
      j--;
    }
    else if(current_index <= index_ptr){
      //printf("two\n");
      u += s[j];
      counts[current_index]--;
    }
    else{
      //printf("three\n");
      t += s[j];
      counts[current_index]--;
    }
  }
  reverse(t.begin(),t.end());
  u += t;
  printf("%s\n",u.c_str());
}
