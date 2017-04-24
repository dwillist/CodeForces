#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(){
  string name1,name2;
  string temp1,temp2;
  int n;
  cin >> name1 >> name2;
  cout << name1 << " " << name2 << endl;
  cin >> n;
  for(int i = 0; i < n; ++i){
    cin >> temp1 >> temp2;
    if(temp1 == name1){
      name1 = temp2;
    }
    else{ // temp1 == name2
      name2 = temp2;
    }
    cout << name1 << " " << name2 << endl;
  }

}
