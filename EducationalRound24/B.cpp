#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>


using namespace std;

vector<int> moves;
vector<int> perm;
set<int> S;

int n,m;

void populate_set(){
  for(int i = 1; i <=n; ++i){
    S.insert(i);
  }
}

int next_op(int start,int next){
  if(next - start > 0){
    return next-start;
  }
  return n - start + next;
}

int main(){
  scanf("%d %d",&n,&m);
  moves.resize(m);
  perm.resize(n,-1);
  populate_set();
  for(int i = 0; i < m; ++i){
    scanf("%d",&moves[i]);
    moves[i]-=1;
  }
  for(int j = 0; j < m-1; ++j){
    int to_insert = next_op(moves[j],moves[j+1]);
    if(perm[moves[j]] == to_insert){
      continue;
    }
    else if(S.find(to_insert) != S.end()){
      S.erase(to_insert);
      if(perm[moves[j]] == -1){
        perm[moves[j]] = to_insert;
      }
      else{
        printf("-1\n");
        return 0;
      }
    }
    else{
      printf("-1\n");
      return 0;
    }
  }
  set<int>::iterator iter = S.begin();
  for(int k = 0; k < perm.size(); ++k){
    if(perm[k] == -1){
      printf("%d ",*iter);
      iter++;
    }
    else{
      printf("%d ",perm[k]);
    }
  }
  printf("\n");
}
