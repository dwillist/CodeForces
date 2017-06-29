#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n,A,c;

map<int,int> M;
int max_map_count = 0;
int max_map_color = 1;
int a_count = 0;

void populate_valid(){
  for(int i = 1; i <= 1000001; ++i)
  if(M[i] != A){
    M[i] = 0;
  }
}

int main(){
  scanf("%d %d",&n,&A);
  populate_valid();
  if(A == 1){
    max_map_color = 2;
  }
  for(int i = 0; i < n;++i){
    scanf("%d",&c);
    if(c == A){
      a_count++;
      map<int,int> M_prime;
      for(auto & elem : M){
        if(elem.second >= max_map_count){
          max_map_count = elem.second;
          max_map_color = elem.first;
        }
        if(elem.second >= a_count){
          M_prime[elem.first] = elem.second;
        }
      }
      M = M_prime;
      if(a_count > max_map_count){
        printf("-1\n");
        return 0;
      }
    }
    else if(M.find(c) != M.end()){
      int cur_count = ++M[c];
      //printf("%d %d\n",cur_count,M[c]);
    }
  }
  printf("%d\n",max_map_color);
}
