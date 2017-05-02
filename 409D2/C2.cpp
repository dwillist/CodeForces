#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

float lo = 0.0;
float hi = 1e12;

vector<pair<int,int> > V;
int n,p;

bool satisfies(float mid){
  float total = 0;
  for(int i = 0; i < n; ++i){
    float val = V[i].second - V[i].first*mid;
    if(val <= 0.0){
      total += val;
    }
  }
  return total < p;
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
  float mid;
  while(hi-lo > .00001){
    printf("in loop %f\n",mid);
    mid = (hi+lo)/2.0;
    if(satisfies(mid)){
      printf("sat\n");
      lo = mid;
    }
    else{
      printf("not sat\n");
      hi = mid;
    }
  }
  printf("%f\n",mid);
}
