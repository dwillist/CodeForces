#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;
typedef long long ll;
int n;
vector<ll> V;

pair<long,int> get_min_diff(vector<ll> v){
  ll min_diff = 12345678910;
  int count = 0;
  for(int i = 1; i < v.size(); ++i){
    ll diff = v[i]-v[i-1];
    if(diff == min_diff){
      count++;
    }
    if(diff < min_diff){
      min_diff = diff;
      count = 1;
    }
  }
  return make_pair(min_diff,count);
}


int main(){
  scanf("%d",&n);
  V.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%I64d",&V[i]);
  }
  sort(V.begin(),V.end());
  pair<ll,int> p = get_min_diff(V);
  printf("%I64d %d\n",p.first,p.second);
}
