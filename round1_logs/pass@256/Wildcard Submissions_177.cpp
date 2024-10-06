
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
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAX_S_LEN = 101;
const int CHAR_S = 26;
const int ALPHABET_SIZE = 26;

bitset<CHAR_S + 1> to_mask(const string& s, int i) {
  bitset<CHAR_S + 1> mask;
  if (s[i] == '?') {
    for (int j = 0; j <= CHAR_S; j++) {
      mask[j] = true;
    }
  } else {
    mask[s[i] - 'A'] = true;
  }
  return mask;
}

int count_nodes(const vector<string>& strings) {
  int nodes[MAX_S_LEN] = {};
  bitset<CHAR_S + 1> current_mask;
  for (int i = 0; i <= CHAR_S; i++) { current_mask[i] = true; }
  nodes[0] = 1;
  for (const string& s : strings) {
    bitset<CHAR_S + 1> next_mask;
    for (int i = 0; i < s.length(); i++) {
      next_mask = to_mask(s, i);
      int count_new_nodes = next_mask.count() - (current_mask & next_mask).count();
      int l = s.length() - i - 1;
      nodes[l + 1] += (long)nodes[l] * count_new_nodes % MOD;
      nodes[l + 1] %= MOD;
      current_mask &= to_mask(s, i);
    }
  }

  int result = 0;
  for (int i = 0; i < MAX_S_LEN; i++) {
    result += nodes[i];
    result %= MOD;
  }
  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<string> strings(N);
    for (int i = 0; i < N; i++) {
      cin >> strings[i];
    }
    cout << "Case #" << t << ": " << count_nodes(strings) << endl;
  }
  return 0;
}
