
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <functional>
#include <string>
#include <vector>
using namespace std;

constexpr int MOD = 998244353;

// Functions for trie node computation
string getParentId(const string& id, int ch);
vector<string> compress_ids(const vector<string>& ids);
int countTrieNodes(const vector<string>& ids);

int main() {
  int T;
  scanf("%d", &T);
  vector<vector<string>> inputs(T);
  for (int t = 0; t < T; t++) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      string id;
      scanf("%s", &id); 
      inputs[t].push_back(id);
    }
  }
  
  // Process each test case
  for (int t = 0; t < T; t++) {
    printf("Case #%d: %d\n", t + 1, countTrieNodes(inputs[t]));
  }
}

string getParentId(const string& id, int ch) {
  int n = id.size();
  const auto& parent_id = id;
  return parent_id.substr(0, n) + ch;
}

vector<string> compress_ids(const vector<string>& ids) {
    vector<string> result(ids);
    set<string> used;
    for(string& id : result){
        if(used.count(id)) id = used.find(id)->data();
        else used.emplace(id);
    }
    return result;
}

int countTrieNodes(const vector<string>& ids) {
  int sz = 0;
  for(auto& id : compress_ids(ids)) {
      sz = (sz + 1) % MOD;
      for (char ch = 'A'; ch <= 'Z'; ch++) {
          if (id.find(ch) != string::npos) {
              string new_id = getParentId(id, ch);
              sz = (sz + countTrieNodes({new_id})) % MOD;
          }
      }
  }
  return sz;
}
