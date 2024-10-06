
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
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

const long long MOD = 998244353;

struct Node {
  unordered_map<char, long long> next = {{}, {0, 1}};
  unordered_map<string, long long> valid_next = {{}, {0, 0}};
  long long sum = 1;
};

void insert(Node* root, string &s, long long res = 1) {
  for(int i = 0; i < s.size(); ++i) {
    char c = s[i];
    if(!root->next.count(c)) {
      root->next[c] = new Node();
    }
    res *= (c == '?'? 26 : 1);
    root->sum += res;
    root->sum %= MOD;
    root = root->next[c];
  }
}

long long solve(string &s) {
  Node* root = new Node();
  root->sum = 1;
  int prev_blank = -1;
  for(int i = 0; i < s.size(); ++i) {
    if(s[i] == '?') {
      prev_blank = i;
    }
  }
  if(prev_blank == -1) {
    insert(root, s);
    return root->sum - 1;
  }
  long long res = 1;
  for(int i = prev_blank + 1; i < s.size(); ++i) {
    res = (26 * res + root->valid_next[s[i]]);
    res %= MOD;
  }
  insert(root, s);
  return res;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N; cin >> N;
    string S[N];
    for (int i = 0; i < N; i++) {
      cin >> S[i];
    }
    long long solution = 0;
    for (int i = 0; i < N; i++) {
      solution += solve(S[i]);
      solution %= MOD;
    }
    cout << (solution + MOD) % MOD << endl;
  }
  return 0;
}
