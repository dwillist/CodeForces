#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int n,k;
vector<long long> A;
long long F = 0;

pair<int,int> right_scan(int right_most){
  long long current_rem = 1;
  int left_most = right_most;
  for(;left_most >= 0; left_most--){
    current_rem = (current_rem*(A[left_most] %k))%k;
    if(current_rem == 0){
      break;
    }
  }
  return make_pair(left_most,right_most);
}


int main(){
  scanf("%d %d",&n,&k);
  A.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%d",&A[i]);
  }
  int last_left = -1;
  int last_right = -1;
  long long current_rem = 1;
  for(int j = 0; j < n; ++j){
    current_rem = (current_rem*(A[j] %k))%k;
    if(current_rem == 0){
      pair<int,int> p = right_scan(j);
      int to_add = (p.first - last_left) * (n-p.second);
      //printf("pair %d,%d adding: %d\n",p.first,p.second,to_add);
      F += (p.first - last_left) * (n-p.second);
      current_rem = 1;
      last_left = p.first;
      last_right = p.second;
      j = last_left;
    }
  }
  printf("%lld\n",F);
}
