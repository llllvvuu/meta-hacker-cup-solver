
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
#include <numeric>
#include <string>
#include <vector>
#include <map>
using namespace std;

const int MOD = 998244353;

long applyMod(long value) {
  return (value % MOD + MOD) % MOD;
}

void processChar(vector<int>& cc, int i, int powersOf26) {
  cc[i] = (cc[i] + powersOf26) % MOD;
}

void addWildcard(const string& pattern, vector<vector<int>>& cc) {
  auto powersOf26 = 1;
  for (auto ch : pattern) {
    if (ch == '?') {
      for (int i = 0; i < 26; i++) {
        processChar(cc[i], i, powersOf26);
      }
    } else {
      int index = ch - 'A';
      processChar(cc[index], index, powersOf26);
    }
    powersOf26 = applyMod(26L * powersOf26);
  }
}

void populateNewSuffixes(const string& pattern, map<vector<int>, int>& incs) {
  int baseIncrement = 1;
  map<vector<int>, int> uniqueSuff;

  for (int i = (int)pattern.size() - 1; i >= 0; --i) {
    auto key = vector<int>();
    for (int j = 0; j <= i; j++) key.push_back(baseIncrement += incs[pattern[i - j]]);

    if (pattern[i] == '?') {
      for (int j = 0; j < 26; j++) uniqueSuff[key]++;
    } else {
      auto id = key;
      id.push_back(baseIncrement++);
      uniqueSuff[id]++;
    }
  }

  for (auto p : uniqueSuff) incs[p.first] += p.second;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    string S[N];
    for (int i = 0; i < N; ++i) cin >> S[i];

    vector<vector<int>> cc(26, vector<int>(1, 1));
    for (int i = 0; i < N; ++i) addWildcard(S[i], cc);
    map<vector<int>, int> incs;
    populateNewSuffixes(S[0], incs);

    int currNodes = 0;
    for (auto i : incs) currNodes = (currNodes + i.second) % MOD;

    cout << currNodes << endl;
  }
}
