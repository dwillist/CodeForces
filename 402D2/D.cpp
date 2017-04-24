#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

char s[200000];
string A;
string B;
vector<int> V;

bool make_able(int max_index){
  //printf("binary searching\n");
  string copyA = A;
  for(int i = 0; i < max_index;++i){
    copyA[V[i]-1] = '\0';
  }
  int indexA = 0;
  int indexB = 0;
  while(indexA < A.size() && indexB < B.size()){
    if(copyA[indexA++] == B[indexB]){
      indexB++;
    }
  }
  //printf("%d indexB\n",indexB);
  return indexB >= B.size();
}

int main(){
  scanf("%s\n",s);
  A = s;
  scanf("%s\n",s);
  B = s;
  V.resize(A.size());
  for(int i = 0; i < A.size(); ++i){
    scanf("%d",&V[i]);
  }
  int hi = A.size();
  int lo = 0;
  while(lo < hi){
    int mid = (hi+lo+1)/2;
    //printf("hi: %d\nlo: %d\nmid: %d\n",hi,lo,mid);
    if(make_able(mid)){
      lo = mid;
    }
    else{
      hi = mid-1;
    }
  }
  printf("%d\n",lo);
}
