#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

char s[100];

int main(){
  int n;
  scanf("%d\n",&n);
  int total = 0;
  for(int i = 0; i < n; ++i){
    scanf("%s\n",s);
    string str_s = s;
    if( str_s == "Tetrahedron"){
      total += 4;
    }
    else if( str_s == "Cube"){
      total += 6;
    }
    else if(str_s == "Octahedron"){
      total += 8;
    }
    else if(str_s == "Dodecahedron"){
      total += 12;
    }
    else if (str_s == "Icosahedron"){
      total += 20;
    }
    else{
      printf("Failed case\n");
      return 1;
    }
  }
  printf("%d\n",total);
  return 0;
}
