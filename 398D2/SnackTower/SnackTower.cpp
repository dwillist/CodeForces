#include <vector>
#include <iostream>

using namespace std;

int main(){
  int n,temp;
  int tower_index =0;
  cin >> n;
  vector<int> tower = vector<int>(n,0);
  for(int i = 0; i < n;++i){
    cin >> temp;
    tower[n-temp] = 1;
    while(tower[tower_index] != 0 && tower_index<tower.size()){
      cout << n - tower_index << " ";
      tower_index++;
    }
    cout << endl;
  }
}
