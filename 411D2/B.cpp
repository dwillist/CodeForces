#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

int n;

int main(){
  scanf("%d",&n);
  string to_return;
  bool b = true;
  to_return.push_back('a');
  for(int i = 1; i < n; ++i){
    if(b){
      to_return.push_back('b');
    }
    else{
      to_return.push_back('a');
    }
    if(i%2 == 0 && i != 0){
      b = !b;
    }
  }
  printf("%s\n",to_return.c_str());
}
