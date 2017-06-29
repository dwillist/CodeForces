#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int k;

bool satsifies(string input,int line_limit, int line_width){
  int line_count = 0;
  int current_distance = 0;
  int last_possible_split = -1;
  for(int i = 0; i < input.size(); ++i){
    current_distance++;
    if(current_distance > line_width && last_possible_split == -1){
      return false;
    }
    if(current_distance > line_width && last_possible_split != -1){
      line_count++;
      current_distance = current_distance -last_possible_split;
      last_possible_split = -1;
    }
    if(input[i] == '-' || input[i] == ' '){
      last_possible_split = current_distance;
    }
  }
  return line_count + 1 <= line_limit;
}

int main(){
  string input;
  int lo = 1;
  int hi = 123456789;
  cin >> k;
  cin.ignore(256, '\n');
  getline(cin,input);
  //cout << "input " << input << endl;
  int mid;
  int best_so_far = 1;
  while(lo <= hi){
    mid = (lo + hi )/2;
    //printf("hi: %d, lo: %d\n",hi,lo);
    if(satsifies(input,k,mid)){
      //cout << "satisfies " << mid << endl;
      best_so_far = mid;
      hi = mid-1;
    }
    else{
      //cout << "unsatisfies " << mid << endl;
      //printf("unsatisfied\n");
      lo = mid+1;
    }
  }
  cout << best_so_far << endl;
}
