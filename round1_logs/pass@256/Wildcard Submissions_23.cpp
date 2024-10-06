
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
#define MOD 998244353
#define MAX_LEN 100
#define MAX_WILDCARDS 25

vector<vector<int>> patterns; // wildcard patterns with values 26 for '?'
int changed[MAX_WILDCARDS + 1];

int process() {
  vector<int> pattern(params[0] + 1, 26); // initialize pattern
  for (int i = 0; i < N; i++) {
    for (int j = 0; patterns[i][j] != 26; j++) {
      pattern[j] = min(pattern[j], patterns[i][j]);
    }
  }
  int nodes = 1, started = 0;
  changed[0] = 0;
  for (int i = 0; i < params[0]; i++) {
    int carry = 0;
    for (int parity = 0; parity < 2; parity++) {
      for (int j = 0; j < N; j++) {
        if ((patterns[j][i] & 1) == parity && patterns[j][i] != 26) {
          if (carry) nodes = (nodes + carry * patterns[j][i]) % MOD;
        } else if (patterns[j][i] == 26) {
          if (carry)
            carry = nodes;
          else {
            carry = started;
            started++;
          }
        }
      }
      changed[started] = carry;
    }
  }
  return nodes;
}

int main() {
  int t;
  cin >> t;
  for (int cas = 1; cas <= t; cas++) {
    vector<string> input_wildcards;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> input_wildcards[i];
      vector<int> p(input_wildcards[i].size(), 0);
      for (int j = 0; j < input_wildcards[i].size(); j++) {
        p[j] = 26;
        if (input_wildcards[i][j] != '?') p[j] -= input_wildcards[i][j] - 'A';
      }
      patterns.push_back(p);
    }
    cout << "Case #" << cas << ": " << process() << endl;
  }
}
