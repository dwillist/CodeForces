#include <vector>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;

int main(){
  int n;
  scanf("%d\n",&n);
  int largest_table = 0;
  int current_sock;
  set<int> table;
  for(int i = 0; i < 2*n - 1; ++i){
    scanf("%d\n",&current_sock);
    if(table.find(current_sock) == table.end()){
      table.insert(current_sock);
    }
    else{
      table.erase(current_sock);
    }
    largest_table = max(largest_table,(int)table.size());
  }
  printf("%d\n",largest_table);
}
