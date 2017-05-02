#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>

using namespace std;

struct Node{
  int value;
  int left;
  int right;
};

int n;
Node T[123456];
bool R[123456] = {0};
map<int,int> Val_Counts;
vector<int> sorted_vec;
int foundCount = 0;

int tree_search(int cur_node,int lo,int hi){
  int found = 0;
  int cur_val = T[cur_node].value;
  if(lo < cur_val && cur_val < hi){
    found += Val_Counts[cur_val];
  }
  if(T[cur_node].left != -1){
    found += tree_search(T[cur_node].left,lo,min(hi,cur_val));
  }
  if(T[cur_node].right != -1){
    found += tree_search(T[cur_node].right,max(lo,cur_val),hi);
  }
  return found;
}


int main(){
  scanf("%d",&n);
  int l,r,v;
  for(int i = 1; i <= n; ++i){
    scanf("%d %d %d", &v,&l,&r);
    Val_Counts[v]++;
    T[i].value = v;
    T[i].left = l;
    T[i].right = r;
    if(l != -1){
      R[l] = true;
    }
    if(r != -1){
      R[r] = true;
    }
  }
  // need to find root node
  int root = 0;
  for(int i = 1; i <= n; ++i){
    if(!R[i]){
      root = i;
      break;
    }
  }
  // now we need a sorted vector of singular values
  for(auto iter:Val_Counts){
    sorted_vec.push_back(iter.first);
  }
  printf("%d\n",n - tree_search(root,-1,1234567899));
}
