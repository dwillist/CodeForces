#include <map>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
map<string,string> full_to_abbr;
map<string,string> abbr_to_full;
vector<string> ordering;
set<string> Aabbrs;



string a_substr(string full){
  return full.substr(0,3);
}

string b_substr(string full){
  string::iterator i = find(full.begin(),full.end(),' ');
  i++;
  return full.substr(0,2) + (*i);
}

bool isB(string full,string substr){
  return substr == b_substr(full);
}

bool isA(string full,string substr){
  return substr == a_substr(full);
}

bool re_hash(string full){
  string abbrA = a_substr(full);
  string abbrB = b_substr(full);
  //printf("full %s \na sub: %s \nb sub: %s \n",full.c_str(),abbrA.c_str(),abbrB.c_str());
  if(abbr_to_full.find(abbrA) == abbr_to_full.end() && Aabbrs.find(abbrA) == Aabbrs.end()){
    full_to_abbr[full] = abbrA;
    abbr_to_full[abbrA] = full;
    Aabbrs.insert(abbrA);
    return true;
  }
  else if(abbr_to_full.find(abbrB) == abbr_to_full.end()){
    full_to_abbr[full] = abbrB;
    abbr_to_full[abbrB] = full;
    if(Aabbrs.find(abbrA) != Aabbrs.end() && abbr_to_full.find(abbrA) != abbr_to_full.end() && abbrB != abbrA){
      string conflict = abbr_to_full[abbrA];
      abbr_to_full.erase(abbrA);
      full_to_abbr.erase(conflict);
      return re_hash(conflict);
    }
    Aabbrs.insert(abbrA);
    return true;
  }
  else{ // there is at least a B conflict
    // need to try to re_hash
    string conflict = abbr_to_full[abbrB];
    Aabbrs.insert(abbrA);
    if(isA(conflict,abbrB)){
      abbr_to_full[abbrB] = full;
      full_to_abbr[full] = abbrB;
      full_to_abbr.erase(conflict);
      return re_hash(conflict);
    }
    return false;
  }
  return false;
}

int main(){
  int n;
  char a[100],b[100];
  scanf("%d\n",&n);
  for(int i = 0; i < n; ++i){
    scanf("%s %s",a,b);
    string a_str = a;
    string b_str = b;
    string full = a_str + " " + b_str;
    ordering.push_back(full);
    if(!re_hash(full)){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for(int i =0; i < ordering.size(); ++i){
    printf("%s\n",full_to_abbr[ordering[i]].c_str());
  }
  return 0;
}
