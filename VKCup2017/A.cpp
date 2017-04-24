#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

char s[234567];
int n,c1,c2,teacher_count;
vector<int> G1,G2;

int solution_search(long long c1,long long c2){
  int lo = 0;
  int hi = 234567;
  while(lo < hi){
    long long x = (hi+lo+1)/2;
    long long sol = c1 - c2*(x-1)*(x-1);
    if(sol>= 0){
      lo = x;
    }
    else{
      hi = x-1;
    }
  }
  return lo;
}

long long cost_calculate(vector<int> & G){
  long long to_return = 0;
  for(int i = 0; i < G.size(); ++i){
    //printf("group %d of size %d\n",i,G[i]);
    to_return += c1 + c2*(G[i]-1)*(G[i]-1);
  }
  return to_return;
}

int main(){
  scanf("%d %d %d",&n,&c1,&c2);
  scanf("%s",s);
  teacher_count = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] == '1'){ teacher_count++;}
  }
  if(c1 > c2){
    int x = solution_search(c1,c2);
    //printf("solution x %d\n",x);
    if((n+x-1)/x > teacher_count){
      printf("teacher count resize\n");
      G1.resize(teacher_count,0);
      G2.resize(teacher_count,0);
    }
    else{
      G1.resize((n+x-1)/x,0);
      G2.resize(n/x,0);
    }
  }
  else{
    G1.resize(teacher_count,0);
    G2.resize(teacher_count,0);
  }
  int g1pos = 0;
  int g2pos = 0;
  for(int j = 0; j < n; ++j){
    G1[g1pos++]++;
    G2[g2pos++]++;
    if(g1pos == G1.size()){g1pos = 0;}
    if(g2pos == G2.size()){g2pos = 0;}
  }
  long long r1,r2;
  r1 = cost_calculate(G1);
  r2 = cost_calculate(G2);
  r1 < r2 ? printf("%I64d\n",r1) : printf("%I64d\n",r2);
}
