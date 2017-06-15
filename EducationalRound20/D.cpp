#include <vector>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int k;

bool satsifies(string input,int limit,int lines){
  int line_count = 0
  int current_distance = 0;
  int last_possible_split = 0;
  for(int i = 0; i < input.size(); ++i){
    current_distance++;
    if(current_distance > limit && last_possible_split == 0){
      return false;
    }
    if(current_distance > limit && last_possible_split){
      line_count++;
      current_distance = current_distance -last_possible_split;
      last_possible_split = 0;
    }
    if(input[i] == '-' || input[i] == ' '){
      last_possible_split = i;
    }
  }
  return line_count + (bool)last_possible_split <= lines;
}

int main(){
  int lo = 1;
  int hi = 123456789;
  scanf("%d",&k);
  int mid;
  while(lo < hi){
    mid = (lo + hi)/2;
    if(satsifies())
  }
}
