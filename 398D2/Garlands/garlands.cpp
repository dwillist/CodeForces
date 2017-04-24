#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstdio>

int rootIndex;
using namespace std;

static pair<int,int> empty_pair = make_pair(-1,-1);

struct Node{
  int temp;
  int total;
  set<Node*> children;
  Node * parent;
  int pos;
};

int populate_totals(Node * current){
  int summation = current->temp;
  for(set<Node*>::iterator iter = current->children.begin(); iter != current->children.end() ; ++iter){
    summation+= populate_totals(*iter);
  }
  current->total = summation;
  return summation;
}

int separate_solution_helper(Node * current,int to_find){
  if(current->total == to_find){
    return current->pos;
  }
  else{
    for(set<Node*>::iterator iter = current->children.begin(); iter!= current->children.end(); ++iter){
      int current = separate_solution_helper(*iter,to_find);
      if(current != -1){
        return current;
      }
    }
  }
  return -1;
}

int find_separate_solutions(Node*root,int to_find,pair<int,int> & solution){
  // we are having some trouble here we need to split our solution
  vector<int> solutions_vec;
  for(set<Node*>::iterator iter = root->children.begin(); iter != root->children.end(); ++iter){
    int current_solution = find_separate_solutions(*iter,to_find,solution);
    if(solution != empty_pair){
      return -1;
    }
    else if(current_solution!= -1){
      solutions_vec.push_back(current_solution);
    }
    if(solutions_vec.size() >1){
      solution.first = solutions_vec[0];
      solution.second = solutions_vec[1];
    }
  }
  if(solutions_vec.empty()){
    if(root->pos != rootIndex && root->total == to_find){
      return root->pos+1;
    }
    return -1;
  }
  return solutions_vec[0];
}

void find_nested_solutions(Node*root,int to_find,int found_above,pair<int,int> & solution){
  if(solution != empty_pair){
    return;
  }
  else if(found_above == -1 && root->pos != rootIndex && root->total == to_find*2){
    for(set<Node*>::iterator iter = root->children.begin(); iter != root->children.end(); ++iter){
      find_nested_solutions(*iter,to_find,root->pos+1,solution);
    }
  }
  else if(root->pos != rootIndex && root->total == to_find && found_above != -1){
    solution.first = found_above;
    solution.second = root->pos+1;
  }
  else{
    for(set<Node*>::iterator iter = root->children.begin(); iter != root->children.end(); ++iter){
    find_nested_solutions(*iter,to_find,found_above,solution);
    }
  }
  return;
}

bool solve(){
  int n,prev,temp;
  scanf("%d\n",&n);
  Node startNode;
  startNode.total = 0;
  startNode.temp = 0;
  startNode.parent = 0;
  vector<Node> tree = vector<Node>(n,startNode);
  for(int i = 0; i < n; ++i){
    scanf("%d %d\n",&prev,&temp);
    tree[i].temp = temp;
    tree[i].pos = i;
    if(prev > 0){
      tree[prev-1].children.insert(&tree[i]);
      tree[i].parent = &tree[prev-1];
    }
    else{
      rootIndex = i;
    }
  }
  populate_totals(&tree[rootIndex]);
  int value = tree[rootIndex].total;
  vector<int> solutions;
  int to_find = value /3;
  if(value %3 != 0){
    printf("-1\n");
    return false;
  }
  pair<int,int> separate = empty_pair;
  find_separate_solutions(&tree[rootIndex],to_find,separate);
  if(separate.first != -1){
    printf("%d %d\n",separate.first,separate.second);
    return true;
  }
  pair<int,int> nested = empty_pair;
  find_nested_solutions(&tree[rootIndex],to_find,-1,nested);
  if(nested.first != -1){
    printf("%d %d\n",nested.first,nested.second);
    return true;
  }
  printf("-1\n");
  return false;
}

int main(){
  solve();
}
