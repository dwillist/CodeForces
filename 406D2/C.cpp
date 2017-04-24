#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

vector<int> Rset;
vector<int> Mset;
vector<int> R_memo;
vector<int> M_memo;
int n;

int m_max(int index,set<int> r_set,set<int> m_set);

int r_max(int index,set<int> r_set,set<int> m_set){
  if(R_memo[index] != -2){
    return R_memo[index];
  }
  else if(r_set.find(index) != r_set.end()){
    //R_memo[index] = 0;
    return 0;
  }
  else{
    r_set.insert(index);
    int to_set = -2;
    for(int i =0; i < Rset.size(); ++i){
      int next_index = (index + Rset[i])%n;
      to_set = max(to_set,-1*m_max(next_index,r_set,m_set));
      if(to_set==1)
        break;
    }
    R_memo[index] = to_set;
    r_set.clear();
    m_set.clear();
    return to_set;
  }
}

int m_max(int index,set<int> r_set,set<int> m_set){
  if(M_memo[index] != -2){
    return M_memo[index];
  }
  else if(m_set.find(index) != m_set.end()){
    //M_memo[index] = 0;
    return 0;
  }
  else{
    m_set.insert(index);
    int to_set = -2;
    for(int i =0; i < Mset.size(); ++i){
      int next_index = (index + Mset[i])%n;
      to_set = max(to_set,-1*r_max(next_index,r_set,m_set));
      if(to_set == 1)
        break;
    }
    M_memo[index] = to_set;
    r_set.clear();
    m_set.clear();
    return to_set;
  }
}

void printV(vector<int> v){
  for(int i = 0; i < v.size(); ++i){
    if(v[i] == 0){
      printf("Loop ");
    }
    else if(v[i] == 1){
      printf("Win ");
    }
    else if(v[i] == -1){
      printf("Lose ");
    }
    else{
      printf("ERR ");
    }
  }
  printf("\n");
}

int main(){
  int r,m;
  //printf("input stuff:\n");
  scanf("%d",&n);
  R_memo.resize(n-1);
  M_memo.resize(n-1);
  for(int i = 0; i < R_memo.size(); ++i){
    R_memo[i] = -2;
    M_memo[i] = -2;
  }
  scanf("%d",&r);
  Rset.resize(r);
  for(int i = 0; i < r; ++i){
    scanf("%d",&Rset[i]);
    int p = n-Rset[i] -1;
    R_memo[p] = 1;
  }
  scanf("%d",&m);
  Mset.resize(m);
  for(int i = 0; i < m; ++i){
    scanf("%d",&Mset[i]);
    int p = n-Mset[i] -1;
    M_memo[p] = 1;
  }
  //printf("scanned\n");
  for(int i =0; i < R_memo.size();++i){
    //printf("i: %d\n",i);
    //printf("R: ");
    //printV(R_memo);
    //printf("M: ");
    //printV(M_memo);
    set<int> a,b;
    r_max(i,a,b);
    m_max(i,b,a);
  }
  printV(R_memo);
  printV(M_memo);
}
