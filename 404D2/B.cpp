#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
  int n,m,temp1,temp2;
  int c_min_end,c_max_begin;
  int p_min_end,p_max_begin;
  c_min_end = p_min_end = 1000000000;
  c_max_begin = p_max_begin = -1;
  scanf("%d\n",&n);
  for(int i = 0; i < n; ++i){
    scanf("%d %d\n",&temp1,&temp2);
      c_min_end = min(temp2,c_min_end);
      c_max_begin = max(temp1,c_max_begin);
  }
  scanf("%d\n",&m);
  for(int j = 0; j < m; ++j){
    scanf("%d %d\n",&temp1,&temp2);
      p_min_end = min(temp2,p_min_end);
      p_max_begin = max(temp1,p_max_begin);
  }
  int to_return = max(c_max_begin - p_min_end,max(p_max_begin - c_min_end,0));
  printf("%d\n",to_return);
}
