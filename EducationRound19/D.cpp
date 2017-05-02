#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

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

void printv(vector<int> & v,int lo,int hi){
  for(int i = lo; i <= hi || i > 20; ++i){
    printf("%d ",v[i]);
  }
  printf("\n");
}

int bin_search(int lo,int hi,int needle,int & split){ // searches between lo and hi for value
  printf("searching for %d\n",needle);
  printv(sorted_vec,lo,hi);
  int mid = (hi+lo)/2;
  while(lo <= hi){
    mid = (hi+lo)/2;
    if(sorted_vec[mid] == needle){
      printf("found!\n");
      split = mid;
      return Val_Counts[needle];
    }
    else if(sorted_vec[mid] > needle){
      hi = mid-1;
    }
    else if(sorted_vec[mid] < needle){
      lo = mid+1;
    }
    else{
      printf("search failed\n");
      return 0;
    }
  }
  split = mid;
  return 0;
}

int tree_search(int current_index,int lo,int hi){
  int split = 0;
  int found = bin_search(lo+1,hi-1,T[current_index].value,split);
  bool delta = found>0;
  if(T[current_index].left != -1){
    int left_index = T[current_index].left;
    found += tree_search(left_index,lo,split-delta);
  }
  if(T[current_index].right != -1){
    int right_index = T[current_index].right;
    found += tree_search(right_index,split+delta,hi);
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
  sort(sorted_vec.begin(),sorted_vec.end());
  int to_print = tree_search(root,0,sorted_vec.size()-1);
  printf("%d\n",n-to_print);
}
