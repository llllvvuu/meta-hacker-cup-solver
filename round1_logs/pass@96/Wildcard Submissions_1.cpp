
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
#include <map>
#include <vector>
using namespace std;

const int MOD = 998244353;
long long power(long long base, int exp) {
  long long res = 1;
  while (exp > 0) {
    if (exp & 1) res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return res;
}

int main() {
  int T, N;
  string S;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> N;
    vector<int> masks(N);
    for (int i = 0; i < N; ++i) {
      cin >> S;
      // Calculate nodes influenced by a wildcard independently
      masks[i] = 0;
      long long currCount = 1LL;
      for (char c : S)
        currCount = (c == '?' ? (currCount * 26LL) % MOD : currCount + 1LL) % MOD;
    }
    map<string, int> freq;
    for (int i = 0; i < N; ++i) {
      string prefix = "";
      for (char c : S) { 
        if (c == '?') break;
        prefix += c;
        (freq[prefix] += 1) %= MOD;
      }
    }
    
    long long nodesCount = 0;
    for (int i = 0; i < N; ++i) 
      nodesCount = (nodesCount + masks[i]) % MOD;
    
    nodesCount = (nodesCount - N + MOD) % MOD;  // Avoid subtracting the root
    for (int i = 0; i < N; ++i)
      nodesCount = (nodesCount + 998244353 - masks[i]) % MOD;

    for (const auto& [prefix, count] : freq)
      nodesCount = (nodesCount + ((MOD - count) * power(26, prefix.size()) % MOD) % MOD) % MOD;

    cout << "Case #" << t << ": " << nodesCount << endl;
  }
  return 0;
}
