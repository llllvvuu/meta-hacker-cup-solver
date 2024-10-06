
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
#include <unordered_map>
#include <iostream>

using namespace std;

constexpr int base = 26;
constexpr int mod = 998244353;
inline int getModCon(int x) { return x < mod ? x : x - mod; }
unordered_map<int, array<int, 2>> children;
unordered_map<int, int> sum;

void insert(const string &s, int parent = 0) {
  int cur = children.find(parent)->second[s[0] - 'A'];
  if (cur == 0) {
    cur = children.size();
    children[parent][s[0] - 'A'] = cur;
  }
  if (s.size() == 1) {
    ++sum[cur];
    return;
  }
  for (char j = 'A'; j <= 'Z'; j++) {
    insert(s.substr(1), cur);
  }
}

int dfs(int root = 0) {
  int ret = sum[root] == 0 ? 1 : sum[root];
  for (int &x : children[root]) {
    ret = getModCon(ret + dfs(x));
  }
  return ret;
}

int readTrie() { return dfs() - 1; }

int insertPattern(const string &s, int parent = 0) {
  int inserted = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '?') {
      ++inserted;
      insert(s.substr(i), parent);
      parent = children.find(parent)->second[s[i] - 'A'];
      continue;
    }
    for (char j = 'A'; j <= 'Z'; j++) {
      int cur = children.find(parent)->second[j - 'A'];
      if (cur != 0) {
        inserted += insertPattern(s.substr(i + 1), cur);
        ++inserted;
      } else {
        int cur = children.size();
        parent = children[parent][j - 'A'] = cur;
        inserted += insertPattern(s.substr(i + 1), cur);
      }
    }
    parent = 0;
  }
  return inserted;
}

int solve() {
  int N;
  cin >> N;
  int cur = readTrie();
  for (int i = 0, insertions; i < N; i++) {
    string s;
    cin >> s;
    sum = {};
    insertions = insertPattern(s);
    cur = getModCon(cur + insertions);
  }
  return cur;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
