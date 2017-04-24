#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

int n,k,size,leader;
vector<int> V;
vector<bool> K;

int remove(int index){
  int move = (V[index])%size;
  while(move){
    //printf("move loop\n");
    leader++;
    if(leader >= n) leader = 0;
    if(K[leader]){move--;}
  }
  K[leader] = false;
  size--;
  int to_return = leader;
  while(!K[leader]){
    //printf("k loop %d\n",leader);
    leader++;
    if(leader >= n){
      leader = 0;
    }
  }
  //printf("new leader at %d\n",leader);
  return to_return;
}

int main(){
  scanf("%d %d\n",&n,&k);
  K.resize(n);
  fill(K.begin(),K.end(),true);
  V.resize(k);
  for(int i = 0; i < k; ++i){
    scanf("%d",&V[i]);
  }
  leader =0;
  size =n;
  for(int i = 0; i < k; ++i){
    printf("%d ",1+remove(i));
  }
  printf("\n");
}
