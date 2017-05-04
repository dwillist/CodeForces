#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

double lo = 0.0;
double hi = 1e13;

vector<pair<int,int> > V;
int n,p;

bool satisfies(double mid){
  double total = 0;
  for(int i = 0; i < n; ++i){
    double val = double(V[i].second) - V[i].first*mid;
    if(val <= 0.0){
      total -= val;
    }
  }
  return total < p*mid;
}

int main(){
  scanf("%d %d",&n,&p);
  long long sum_check = 0;
  for(int i = 0; i < n; ++i){
    int a,b;
    scanf("%d %d",&a,&b);
    sum_check += a;
    V.push_back(make_pair(a,b));
  }
  if(sum_check <= p){
    printf("-1\n");
    return 0;
  }
  double mid;
  while(hi-lo > .00001){
    //printf("in loop %f %f\n",lo,hi);
    mid = (hi+lo)/2.0;
    if(satisfies(mid)){
      lo = mid;
    }
    else{
      hi = mid;
    }
  }
  printf("%f\n",mid);
}
