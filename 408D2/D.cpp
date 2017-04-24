#include <vector>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <deque>
#include <set>


using namespace std;

struct node_state{
  int node;
  int distance;
  int color;
};

vector<int> A[1234567];
int V[1234567] = {0};
int n,k,d;
map<pair<int,int>,int> M;
deque<node_state> q;
set<int> to_del;
int del_count = 0;

void BFS(deque<node_state> & q){
  node_state extra;
  while(!q.empty()){
    node_state s = q.front();
    //printf("node: %d, color: %d\n",s.node,s.color);
    q.pop_front();
    if(V[s.node] == s.color){
      if(s.distance < d){
        for(auto next:A[s.node]){
          if(V[next] && (V[next] != s.color)){
            int n1,n2;
            n1 = min(next,s.node);
            n2 = max(s.node,next);
            pair<int,int> to_find = make_pair(n1,n2);
            if(to_del.find(M[to_find]) == to_del.end()){
              del_count++;
              to_del.insert(M[to_find]);
            }
          }
          else if(!V[next]){
            extra.node = next;
            extra.distance = s.distance+1;
            extra.color = s.color;
            V[next] = s.color;
            q.push_back(extra);
          }
        }
      }
    }
  }
}

int main(){
  node_state builder;
  scanf("%d %d %d\n",&n,&k,&d);
  for(int i = 0; i < k; ++i){
    int temp;
    scanf("%d ",&temp);
    if(!V[temp]){
      V[temp] = i+1;
      builder.node = temp;
      builder.color = i+1;
      builder.distance = 0;
      q.push_back(builder);
    }
  }
  for(int j = 0; j < n-1; ++j){
    int a,b;
    scanf("%d %d\n",&a,&b);
    if(b < a){
      swap(a,b);
    }
    M.insert(make_pair(make_pair(a,b),j+1));
    A[a].push_back(b);
    A[b].push_back(a);
  }
  if(d == 0){
    printf("%d\n",n-1);
    for(int i = 1; i <=n-1; ++i)
    printf("%d ",i);
  }
  else{
    BFS(q);
    printf("%d\n",del_count);
    for(int tp:to_del){
      printf("%d ",tp);
    }
  }
  printf("\n");
}
