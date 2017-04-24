#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;
vector<int> V[1234567];
int M[1234567];
pair<int,int> f = make_pair(0,0);
pair<int,int> s = make_pair(0,0);
int n;

pair<int,int> count_adjacent(int start){
  int f_count = 0;
  int s_count = 0;
  for(int i : V[start]){
    if(M[i] == f.first){ f_count++;}
    if(M[i] == s.first){ s_count++;}
  }
  return make_pair(f_count,s_count);
}

int main(){
  int s1,s2;
  scanf("%d",&n);
  for(int i = 1; i <= n; ++i){
    scanf("%d ",&M[i]);
    if(f.second == 0 || f.first < M[i]){
      s = f;
      f.first = M[i];
      f.second = 1;
    }
    else if(M[i] == f.first){
      f.second++;
    }
    else if(s.second == 0 || s.first < M[i]){
      s.first = M[i];
      s.second = 1;
    }
    else if(M[i] == s.first){
      s.second++;
    }
  }
  for(int j = 0; j < n-1; ++j){
    scanf("%d %d\n",&s1,&s2);
    V[s1].push_back(s2);
    V[s2].push_back(s1);
  }
  int min_pow = f.first + 2;
  for(int k = 1; k <= n; ++k){
    pair<int,int> c = count_adjacent(k);
    if(M[k] != f.first){ // starting at non-max
      if(c.first == f.second){
        min_pow = min(min_pow,f.first+1);
      }
    }
    else{ // starting at max
      if(c.first == f.second-1){
        if(c.second == s.second){
          min_pow = min(min_pow,f.first + (f.second > 1)); // we can be done here if needed
        }
        else{
          min_pow = min(min_pow,max(f.first + (f.second>1),(s.second>0)*(s.first+2)));
        }
      }
    }
  }
  printf("%d\n",min_pow);
}
