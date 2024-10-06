
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
#include <vector>
using namespace std;

const int MOD = 998244353;
const int N = 101;
int trie[N][26]{}, trieSizes[N]{};

// Initialize trie to consist just of root
void init() {
  fill(trieSizes, trieSizes + N, 0);
}

// Update the trie and calculate sum of node creations in its subtree
long long recurse(string& s, int node = 0, int i = 0) {
  long long ans = trieSizes[node];
  while (i < s.size() && s[i] == '?') {
    ans = (ans * 26) % MOD;
    i++;
  }
  for (; i < s.size(); i++) {
    int next = s[i] - 'A';
    if (trie[node][next] == 0) {
      trie[node][next] = ++trieSizes[node];
    }
    node = trie[node][next];
    ans = (ans + recurse(s, node, i + 1)) % MOD;
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    init();
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
      cin >> S[i];
    cout << "Case #" << t << ": " << recurse(S[0]) << endl;
  }
  return 0;
}
