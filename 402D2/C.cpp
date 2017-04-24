#include<vector>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<functional>

using namespace std;

int main(){
  int n,k;
  vector<int> A;
  vector<int> B;
  vector<pair<int,int> > Diff;
  scanf("%d %d\n",&n,&k);
  A.resize(n);
  B.resize(n);
  Diff.resize(n);
  for(int i = 0; i < n; ++i){ scanf("%d ",&A[i]);}
  for(int i = 0; i < n; ++i){ scanf("%d ",&B[i]);}
  for(int i = 0; i < n; ++i){
    Diff[i] = make_pair(B[i] - A[i],A[i]);
  }
  sort(Diff.begin(),Diff.end(),greater<pair<int,int> >());
  // now largest difference will be first
  int total_sum = 0;
  for(int i = 0; i < n; ++i){
    if(i < k){
      total_sum += Diff[i].second;
    }
    else{
      total_sum += min(Diff[i].first + Diff[i].second,Diff[i].second);
    }
  }
  printf("%d\n",total_sum);
}
