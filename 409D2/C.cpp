#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

vector<pair<long long,long long> > V;
int n;
int p;

bool less_than(pair<long long,long long> & A,pair<long long, long long> & B){
  return A.second * B.first < A.first * B.second;
}

int main(){
  scanf("%d %d",&n,&p);
  for(int i = 0; i < n; ++i){
    int a,b;
    scanf("%d %d",&a,&b);
    long long a1 = a;
    long long b1 = b;
    V.push_back(make_pair(a1,b1));
  }
  sort(V.begin(),V.end(),less_than);
  pair<long long,long long> current = V[0];
  current.first -= p;
  for(int i = 1; i < V.size(); ++i){
    pair<long long,long long> temp = current;
    temp.first += V[i].first;
    temp.second += V[i].second;
    if(less_than(temp,current)){
      current = temp;
    }
  }
  if(current.first <= 0){
    printf("-1\n");
    return 0;
  }
  double num = (double) current.second;
  double denom = (double) current.first;
  double solution = num/denom;
  printf("%f\n",solution);

}
