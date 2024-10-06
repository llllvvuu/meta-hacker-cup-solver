
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
#include <unordered_map>
using namespace std;

using mod = int;
const mod kMod = 998244353;

struct trie {
  unordered_map<char, trie*> next;
  long long cnt = 0;
};

mod solve() {
  trie t;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    trie* curr = &t;
    for (char ch : S) {
      if (ch != '?') {
        auto it = curr->next.find(ch);
        if (it == end(curr->next)) {
          it = curr->next[ch] = new trie();
        }
        curr = it->second;
        curr->cnt++;
      }
    }
  }
  mod ans = 0;
  for (auto& [_, ct] : t.next) {
    ans = (ans + ct->cnt) % kMod;
  }
  ans++;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    trie* curr = &t;
    for (char ch : S) {
      if (ch == '?') {
        for (auto& [nxtch, nxt] : curr->next) {
          ans = (ans + nxt->cnt) % kMod;
        }
        break;
      }
      curr = curr->next[ch];
    }
  }
  return ans;
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
