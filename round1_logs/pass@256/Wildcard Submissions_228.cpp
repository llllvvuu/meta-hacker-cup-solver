
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
#include <map>
#include <string>
using namespace std;

const int MOD = 998244353;

pair<int, int> analyze(const string& str, int i = 0) {
  if (i == str.size()) return make_pair(1, str.size());
  if (str[i] != '?') return make_pair(analyze(str, i+1).first, str.size() - i);
  pair<int, int> rec = analyze(str, i+1);
  int pow = 1;
  for (size_t j = i; j < str.size(); ++j)
    pow = (pow * 26) % MOD, rec.first = (rec.first + pow) % MOD;
  return rec;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    map<int, int> mp;
    for (int n = 0; n < N; n++) {
      string S;
      cin >> S;
      auto [pre, len] = analyze(S);
      mp[pre] = (mp[pre] + len + 1) % MOD;
    }
    long long sum = 0;
    for (auto& [prefix, cnt]: mp)
      sum = (sum + cnt) % MOD;
    cout << "Case #" << t << ": " << sum << endl;
  }
  return 0;
}
