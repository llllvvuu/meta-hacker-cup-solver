
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
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

constexpr int mod = 998244353;

struct Entry { // Use this to identify nodes which themselves should be counted separately.
  int letter;
  int next;
};

vector<string> strings;
vector<Entry> jumps;      // Jumps at that index, straight to the end.
vector<int> ans;            // Number of nodes from here down, with wildcards at the end only.
int next[105];     // Next node after i.

int solve(int i) {
  if (ans[i] != -1) {
    return ans[i];
  }
  if (next[i] == i + 1) {
    int ans_ = 1;
    int offset = 1;
    while (jumps[i + offset].letter != 27) {
      offset += 1;
      ans_ = (int64_t)ans_ * 26 % mod;
    }
    ans[i] = ans_;
    return ans_[1];
  }
  ans[i] = 1;
  for (int j = i + 1; j < next[i]; ++j) { // Go to the earliest next[i].
    ans[i] = (ans[i] + int64_t(solve(j)) * 26 % mod) % mod;
  }
  ans[i] += solve(next[i]);
  return ans[i];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int qi = 0; qi < t; ++qi) {
    int n;
    cin >> n;
    strings = vector<string>(n);
    for (int i = 0; i < n; ++i) {
      cin >> strings[i];
    }
    jumps = vector<Entry>();
    ans = vector<int>(strings.size() * 100 + 1, -1);
    for (size_t i = 0; i < strings.size(); ++i) {
      for (size_t j = 0; j < strings[i].size(); ++j) {
        if (strings[i][j] != '?') {
          jumps.push_back({strings[i][j] - 'A' + 1, (int)strings[i].size() - j - 1});
          next[i * 100 + j] = jumps.size();
        }
      }
      if (strings[i][strings[i].size() - 1] == '?') {
        jumps.push_back({27, -1});
        next[i * 100 + strings[i].size() - 1] = jumps.size();
      }
    }
    long long ans_ = 1;
    for (int i = 0; i < 100; ++i) {
      if (strings[0][i] != '?') {
        ans_ = int64_t(ans_ * 26) % mod;
      }
    }
    printf("%sCase #%d: %llu\n",
           qi == 0 ? "" : "\n", qi + 1, (ans_ + solve(jumps.size() - 1)) % mod);
  }
  return 0;
}
