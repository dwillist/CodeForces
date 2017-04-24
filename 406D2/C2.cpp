#include <vector>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <deque>

using namespace std;

int arr[7999][2] = {0};
int stack_set[7999][2] = {0};
int rick[7999];
int morty[7999];
int n,r,m;

int next_index(int current){
  return current % (n);
}

void printA(int a[7999][2],int n,int j){
  for(int i = 1; i < n; ++i){
    int next = a[i][j];
    if(next == 1){
      printf("Win ");
    }
    else if(next == -1){
      printf("Lose ");
    }
    else{
      printf("Loop ");
    }
  }
  printf("\n");
}


int prev_index(int value){
  if(value < 0){
    return value +n;
  }
  return value;
}

int other_person(int p){
  return (p+1)%2;
}

// 1 -> morty
// 0 -> rick
// lets use BFS to solve this
void bfs_solve(deque<pair<int,int> > & stack){
  while(!stack.empty()){
    int index = stack.front().first;
    int person = stack.front().second;
    stack_set[index][person] = 0;
    stack.pop_front();
    if(arr[index][person] != 0){
      continue;
    }
    //printf("recursing on %d for %d\n",index,person);
    int min_value_found = 1;
    bool assigned = false;
    int * moves;
    int * other_moves;
    int limit;
    int other_limit;
    if(person == 1){ // morty
      moves = &morty[0];
      other_moves = &rick[0];
      limit = m;
      other_limit = r;
    }
    else{
      moves = &rick[0];
      other_moves = &morty[0];
      limit = r;
      other_limit = m;
    }
    for(int i =0; i < limit; ++i){
      int next_pos = (index + *(moves+i))%n;
      if(arr[next_pos][other_person(person)] == -1){
        // we are done
        arr[index][person] = 1;
        assigned = true;
      }
      min_value_found = min(min_value_found,arr[next_pos][other_person(person)]);
    }
    if(!assigned && min_value_found == 1){
      arr[index][person] = -1;
      assigned = true;
    }
    // now need to update our stack
    // adding all indicis that could reach the current node
    if(assigned){
      for(int j = 0; j < other_limit; ++j){
        pair<int,int> next_pair = make_pair(prev_index(index - *(other_moves+j)),other_person(person));
        if(arr[next_pair.first][next_pair.second] == 0 && stack_set[next_pair.first][next_pair.second] == 0){
          stack.push_back(next_pair);
          stack_set[next_pair.first][next_pair.second] = 1;
        }
      }
    }
  }
}

int main(){
  scanf("%d",&n);
  scanf("%d",&r);
  deque<pair<int,int> > stack;
  pair<int,int> to_add;
  for(int i = 0; i < r; ++i){
    scanf("%d",&rick[i]);
    to_add = make_pair(prev_index(0-rick[i]),0);
    stack.push_back(to_add);
    stack_set[to_add.first][to_add.second] = 1;
  }
  scanf("%d",&m);
  for(int i = 0; i < m; ++i){
    scanf("%d",&morty[i]);
    to_add = make_pair(prev_index(0-morty[i]),1);
    stack.push_back(to_add);
    stack_set[to_add.first][to_add.second] = 1;
  }
  arr[0][0] = -1;
  arr[0][1] = -1;
  bfs_solve(stack);
  printA(arr,n,0);
  printA(arr,n,1);
}
