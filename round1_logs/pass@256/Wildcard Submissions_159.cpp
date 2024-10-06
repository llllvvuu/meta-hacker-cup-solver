
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

typedef long long ll;
const int MOD = 998244353;

// Function to generate the set of prefixes for a given wildcard string
void gen(const string &w, map<string, int> &vocab, int len) {
  if (len == (int)w.size() || w[len] == '?') {
    vocab[w.substr(0, len)] += 1;
    return;
  }
  gen(w, vocab, len + 1);
}

// Recursive function to generate concrete strings matching the wildcard
void f(const string &w, int match, map<string, int> &vocab) {
  if (match == (int)w.size()) {
    gen(w, vocab, 0);
    return;
  }
  f(w, match + 1, vocab);
  if (w[match] == '?') {
    f(w, match + 1, vocab);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    map<string, int> vocab;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
      string W;
      cin >> W;
      f(W, 0, vocab);
    }

    ll ans = 0;
    for (const auto &word : vocab) {
      ans += word.second;
      ans %= MOD;
    }
    cout << "Case #" << t << ": " << ans << "\n";
  }
}
