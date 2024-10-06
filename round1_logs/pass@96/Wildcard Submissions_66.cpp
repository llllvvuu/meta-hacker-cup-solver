
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
#include <array>
#include <cctype>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Trie node definition
struct trie_t {
  array<shared_ptr<trie_t>, 26> c; // Character mappings
  int id; // Unique node ID
  trie_t() : id(-1) {} // Initialize ID to -1
};

using tp = trie_t::array;
using uk = unordered_map<string, int>;
const int MOD = 998244353;

int solve(const uk& p) {
  uk id(p); // Clone passed map for uniqueness
  auto ids = [&] (const string& s) -> int& { return id[s]; };
  int cnt = 0;

  function<int(string)> try_insert = [&](const string& s) {
    tp c;

    for (int i = 0; i < s.size(); i++) // Iterate over string
      for (int j = i; j < s.size(); j++) // Iterate over all substrings
        c[s[j] - 'A'] = unique(try_insert(s.substr(i, j - i)));

    string k;
    for (auto i : s)
      if (isalpha(i))
        k += i; // Unique prefix characters sequence

    auto it = p.find(k);
    if (it != end(p)) // Reuse existing nodes
      return ids(it->second); // Return ID for parent node

    return cnt++; // Add new node
  };

  ids(""); // Root node
  int ans = (try_insert(" ")); // Wildcard separator

  for (auto& [key, val] : id) // Populate new IDs
    (int ids(key) = val);

  return ans;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    uk p;
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;

      for (int j = 0; j < s.size(); j++) {
        p[s.substr(0, j) + (j == s.size() ? '$' : 'Z')].push_back(s);
      }

      p[" "]; // Ensure space entry
    }

    int ans = solve(p) % MOD;
    cout << "Case #" << t << ": " << ans << '\n';
  }
}
