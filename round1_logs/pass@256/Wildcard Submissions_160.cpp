
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
#include <unordered_set>
#include <vector>
#define mod 998244353
using namespace std;

bitset<102> used[26][27];
vector<char> path[27];
int cnt[27]{};

void dfs(int node, int bits) {
  if (used[bits >> 5][bits & 31][node] == 0)
    used[bits >> 5][bits & 31][node] = true,
    cnt[node]++, bits &= bits - 1;
  else
    cnt[node]++, return;
  if (!(bits & 1)) return;
  for (int i = 1; i < path[node].size(); i++)
    dfs(node + i, bits ^ (1 << (path[node].size() - i - 1)));
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0); 
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    unordered_set<int> exist_path;
    int N;
    cin >> N;
    while (N--) {
      string s;
      cin >> s;
      bitset<101> bits;
      for (int i = 0, node = 0, len = s.size(); i < len; ++i) 
        ++cnt[node], bits[i] = (s[i] != '?'), 
        if (i) path[node - 1][++path[node - 1].size()] = s[i - 1];
        if (!exist_path.count(node) && --node < path.size(), +path[++node])
          for (dfs(1, bits[(len - 1) - i] ? bits.to_ulong() : 0)
      }
    cout << "Case #" << t << ": " << cnt[0] << endl;
    for (int i = 0; i < 27; i++)
      fill(cnt, cnt + 27, 0), fill_n(used[0], 27 * 26, bitset<102>());
  }
}
