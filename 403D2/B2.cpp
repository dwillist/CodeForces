#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
  int n;
  vector<double> x,v;
  scanf("%d\n",&n);
  x.resize(n);
  v.resize(n);
  for(int i = 0; i < n; ++i){
    scanf("%lf\n",&x[i]);
  }
  for(int j = 0; j < n; ++j){
    scanf("%lf\n",&v[j]);
  }
  //now vectors are filled binary search time
  double t_lower = 0;
  double t_upper = 1e10;
  for(int ui = 0; ui < 100; ++ui ){
    double t = (t_upper + t_lower)/2.0;
    double l = -1e10;
    double r = 1e10;
    for(int i = 0; i < x.size(); ++i){
      l = max(x[i] - v[i]*t,l);
      r = min(x[i]+v[i]*t,r);
    }
    if(r > l-(1e-8)){
      //interval is non empty so lets look for smaller values of t
      t_upper = t;
    }
    else{
      // interval is empty so need larger values of t
      t_lower = t;
    }
  }
  printf("%.10lf\n",t_lower);
}
