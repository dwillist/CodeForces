#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<long long> VA;
vector<long long> VB;
vector<int> indicies;

bool sort_func(int index1,int index2){
  return VA[index1] > VA[index2];
}

int main(){
  scanf("%d",&n);
  VA.resize(n);
  VB.resize(n);
  indicies.resize(n);
  for(int i = 0; i < n ; ++i){
    scanf("%d",&VA[i]);
    indicies[i] = i;
  }
  for(int i = 0; i < n ; ++i){
    scanf("%d",&VB[i]);
  }
  sort(indicies.begin(),indicies.end(),sort_func);
  /*for(int i = 0; i < n; ++i){
    printf("%d ",indicies[i]);
  }
  printf("\n");
  for(int i = 0; i < n; ++i){
    printf("%d ",VA[indicies[i]]);
  }
  printf("\n");
  for(int i = 0; i < n; ++i){
    printf("%d ",VB[indicies[i]]);
  }
  printf("\n");
  */
  vector<int> chosen_indicies;
  chosen_indicies.push_back(indicies[0]);
  for(int j = 1; j < n-1; j+=2){
    if(VB[indicies[j]] > VB[indicies[j+1]]){
      chosen_indicies.push_back(indicies[j]);
    }
    else{
      chosen_indicies.push_back(indicies[j+1]);
    }
  }
  if(n%2 == 0){
    chosen_indicies.push_back(indicies[n-1]);
  }
  printf("%d\n",n/2 + 1);
  for(int k = 0; k < chosen_indicies.size(); ++k){
    printf("%d ",chosen_indicies[k]+1);
  }
  printf("\n");
}
