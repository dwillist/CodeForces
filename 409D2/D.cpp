#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>

double C = 10e9;

using namespace std;

struct Point{
  double x;
  double y;
  double distance(const Point & P){
    return sqrt(pow(x - P.x,2) + pow(y - P.y,2));
  }
};

struct Line{
  Point P1;
  Point P2;
  double distance(const Point & P){
    return double(abs((P2.y - P1.y)*P.x - (P2.x - P1.x)*P.y + P2.x*P1.y - P2.y*P1.x))/
          sqrt(pow(P2.y - P1.y,2) + pow(P2.x - P1.x,2));
  }
};

vector<Line> VL;
vector<Point> VP;
int n;
double max_distance = 2e11;

bool satisfies(double mid){
  for(int i =0; i < n; ++i){
    //printf("calculating for i=%d with distance %f\n",i,VL[i].distance(VP[i+1]));
    if(VL[i].distance(VP[(i+1)%n]) < mid*2){
      //printf("Fails for i=%d with distance %f\n",i,VL[i].distance(VP[i+1]));
      return false;
    }
  }
  return true;
}

int main(){
  scanf("%d",&n);
  for(int i = 0; i < n; ++i){
    int x,y;
    scanf("%d %d",&x,&y);
      Point P;
      P.x = x;
      P.y = y;
      VP.push_back(P);
      if(i >= 2){
        Line L;
        L.P1 = VP[i-2];
        L.P2 = P;
        VL.push_back(L);
      }
  }
  Line L1,L2;
  L1.P1 = VP[0];
  L1.P2 = VP[n-2];
  L2.P1 = VP[1];
  L2.P2 = VP[n-1];
  VL.push_back(L1);
  VL.push_back(L2);
  // add edges that connect first to last.
  for(int i = 0; i < n; ++i){
    for(int j = i+1; j < n; ++j){
      max_distance = min(max_distance,VP[i].distance(VP[j])/2.0);
    }
  }
  max_distance = min(max_distance,VP[0].distance(VP[n-1]));
  double hi = max_distance;
  double lo = 0;
  double mid = 1;
  //printf("at pre loop %f %f\n",lo,hi);
  while((hi - lo)/max(1.0,mid) > .0000001){
    mid = (hi+lo)/2.0;
    //printf("mid %f\n",mid);
    if(satisfies(mid)){
      lo  = mid;
    }
    else{
      hi = mid;
    }
  }
  //printf("at end %f %f\n",lo,hi);
  printf("%f\n",mid);
}
