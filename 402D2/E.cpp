#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <iostream>
#include <assert.h>

using namespace std;

class operation{
public:
  int op1;
  int op2;
  string opp;
  int result_name;

  operation(int o1,int o2,string op,int res):
    op1(o1),op2(o2),opp(op),result_name(res){}
};

vector<string> parse(string & s, string kar){
  string::iterator iter = s.begin();
  string::iterator next;
  vector<string> to_return;
  while(iter != s.end()){
    while(iter != s.end() && find(kar.begin(),kar.end(),*iter) != kar.end())
      iter++;
    next = find_first_of(iter,s.end(),kar.begin(),kar.end());
    to_return.push_back(string(iter,next));
    iter = next;
  }
  return to_return;
}

bool evaluate(operation O,unordered_map<int,bitset<1000> > & M,int bit_pos){
  bool to_return;
  if(O.opp == "XOR"){
    to_return = M[O.op1][bit_pos] ^ M[O.op2][bit_pos];
  }
  else if(O.opp == "AND"){
    to_return = M[O.op1][bit_pos] & M[O.op2][bit_pos];
  }
  else if(O.opp == "OR"){
    to_return = M[O.op1][bit_pos] | M[O.op2][bit_pos];

  }
  M[O.result_name];
  M[O.result_name][bit_pos] = to_return;
  return to_return;
}

int simulate(vector<operation> & O, unordered_map<int,bitset<1000> > M,int bit_pos,bool my_bit,int id_pos){
  M[id_pos][bit_pos] = my_bit;
  int to_return = 0;
  for(int i = 0; i< O.size(); ++i){
    to_return += evaluate(O[i],M,bit_pos);
  }
  return to_return;
}


int main(){
  int n,m;
  unordered_map<int,bitset<1000> > M;
  unordered_map<string,int> ids;
  vector<operation> Opp_list;
  string s;
  cin >> n >> m;
  cin.ignore();
  int id_pos = 0;
  ids["?"] = 0;
  for(int i = 0; i < n;++i){
    getline(cin,s);
    vector<string> line = parse(s," :=");
    // vector will be of length 2 or 4
    if(line.size() == 2){
      M.insert(make_pair((int)ids.size(),bitset<1000>(line[1])));
      ids.insert(make_pair(line[0],(int)ids.size()));
    }
    else{
      //cout << "op1 "<<line[1]<<" op2 "<<line[3]<<" opp "<<line[2]<<" result_name "<<line[0]<<endl;
      ids.insert(make_pair(line[0],(int)ids.size()));
      Opp_list.push_back(operation(ids[line[1]],ids[line[3]],line[2],ids[line[0]]));
    }
  }
  // now lists should be filled
  bitset<1000> to_return1;
  bitset<1000> to_return2;
  for(int j = m-1; j >= 0; --j){
    int a = simulate(Opp_list,M,j,1,id_pos);
    int b = simulate(Opp_list,M,j,0,id_pos);
    //printf("a: %d \nb: %d\n",a,b);
    if(a > b){
      to_return1[m-1 - j] = 1;
      to_return2[m-1 - j] = 0;
    }
    else if( a == b){
      to_return1[m-1 - j] = 0;
      to_return2[m-1 - j] =0;
    }
    else{
      to_return1[m-1 - j] = 0;
      to_return2[m-1 - j] = 1;
    }
  }
  for(int i = 0; i < m; ++i){ cout << to_return2[i];}
  cout << endl;
  for(int i = 0; i < m; ++i){ cout << (to_return1[i]);}
  cout << endl;
}
