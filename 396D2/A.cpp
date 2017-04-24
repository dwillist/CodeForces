#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){
  string A,B;
  cin >> A;
  cin >> B; // this should give us strings A,B
  if(A == B){
    cout << -1 << endl;
    return 0;
  }
  else{
    cout << max(A.size(),B.size()) << endl;
    return 0;
  }
}
