// not so nice brute force approach

#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

string func(string & s){
  string to_return = s.substr(1);
  to_return.push_back(s[0]);
  return to_return;
}

// turn s1 into s2
int dist(string &s1, string & s2){
  string s1prime = s1+s1;
  for(int i = 0; i < s2.size(); ++i){
    if(s1prime.substr(i,s1.size()) == s2){
      return i;
    }
  }
  return -1; // no solution
}

int main(){
  vector<string> v;
  int n;
  char s [51];
  scanf("%d",&n);
  for(int i =0; i < n; ++i){
    scanf("%s",s);
    v.push_back(string(s));
  }
  string begin_str = v[0];
  int min_total_dist = 50*50;
  for(int j = 0; j < begin_str.size(); ++j){
    int total_dist = 0;
    for(int l = 0; l < n; ++l){
      int d = dist(v[l],begin_str);
      //printf("startstring: %s endstring: %s dist: %d\n",v[l].c_str(),begin_str.c_str(),d);
      if(d >= 0){
        total_dist += d;
      }
      else{
        printf("-1\n");
        return 0;
      }
    }
    min_total_dist = min(min_total_dist,total_dist);
    //printf("min total distance: %d\n",min_total_dist);
    begin_str = func(begin_str);
  }
  printf("%d\n",min_total_dist);
}
