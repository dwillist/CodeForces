//Codeforce Molly's chemicals

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;
static long long limit = 100000000000000;

//long long A[100001];
map<long long,int> val_to_index_map;

long long mabs(long long a){
  if(a < 1){a*= -1;}
  return a;
}


int main(){
  int n,k;
  long long sum,temp,to_print;
  long long max_possible = 0;
  to_print = 0;
  sum = 0;
  val_to_index_map[sum]++;
  scanf("%d %d\n",&n,&k);
  for(int i = 0; i < n; ++i){
    scanf("%lld ",&temp);
    sum += temp;
    max_possible += mabs(temp);
    long long cur = 1;
    while(cur <= max_possible){
      //printf("sum %lld looking up %lld\n",sum,sum-cur);
      to_print += val_to_index_map[sum - cur];
      cur = cur * k;
      if(cur == 1){
        break;
      }
    }
    val_to_index_map[sum]++;
  }
  // now we should have an unordered map
  printf("%lld\n",to_print);
}
