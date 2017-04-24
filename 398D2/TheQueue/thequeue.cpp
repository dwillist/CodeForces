#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

long solve(){
  long ts,tf,t;
  long n,temp;
  vector<long> A,B;
  cin >> ts >>tf >> t;
  cin >>n;
  if(n == 0){
    return ts;
  }
  long best_time;
  long longest_wait = tf;
  long current_serve_time;
  long previous_serve_time;
  for(long i = 0; i < n; ++i){
    cin >> temp;
    A.push_back(temp);
    if(i == 0){
      current_serve_time = ts;
    }
    else{
      previous_serve_time = current_serve_time;
      current_serve_time = max(temp,current_serve_time+t);
    }
    if(temp == 0 ||(i!=0 && temp == A[i-1]) || current_serve_time+t > tf){
      continue;
    }
    else if(temp <= ts && current_serve_time - temp + 1 < longest_wait){
      longest_wait = current_serve_time - temp +1;
      best_time = temp -1;
    }
    else if(current_serve_time - temp < longest_wait){
      longest_wait = current_serve_time - temp;
      best_time = temp-1;
    }
    if(i!=0 && temp - (previous_serve_time+2*t) >= 0){
      longest_wait = 0;
      best_time = previous_serve_time+t;
    }
  }
  if(current_serve_time+2*t <= tf){
    best_time = tf-t;
  }
  return best_time;
}

int main(){
  printf("%ld\n",solve());
}
