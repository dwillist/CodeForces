#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

double meet_time(pair<int,int> A,pair<int,int> B){
  return (double)abs(A.first - B.first)/(double)(A.second+B.second);
}

int main(){
  int n,temp;
  vector<int> X;
  vector<int> Y;
  scanf("%d\n",&n);
  X.resize(n);
  Y.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%d\n",&X[i]);
  }
  for(int i = 0; i < n; ++i){
    scanf("%d\n",&Y[i]);
  }
  // now X,Y are filled
  double time_diff = 0;
  pair<int,int> lower,upper;
  lower.first = X[0];
  lower.second = Y[0];
  upper = lower;
  for(int k = 1; k < n;++k){
    pair<int,int> current_pair = make_pair(X[k],Y[k]);
    double c1 = meet_time(current_pair,upper);
    double c2 = meet_time(current_pair,lower);
    if(c1 > time_diff && c1 >= c2){
        time_diff = c1;
        lower = current_pair;
    }
    else if(c2 > time_diff && c2>=c1){ //X[k] >= upper.first
        time_diff = c2;
        upper = current_pair;
    }
  }
  printf("%.10lf\n",time_diff);
}
