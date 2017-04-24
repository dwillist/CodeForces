#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
  int a = 5;
  if (a == 2){
    printf("a is 2\n");
  }
  else{
    printf("a is not 2\n");
  }
  if(a == 5){
    printf("post else - if statement executed\n");
  }
  printf("post else statement non conditional code executed\n");
}
