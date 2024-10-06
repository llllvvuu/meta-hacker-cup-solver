
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
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

const int M = 998244353; // Modulo constant
const int N = 1 << 26;   // Upper bound for any variable

int t, n, sz;
vector<string> wildcards;
unordered_map<string, bool> cnt;
int power26[N], depth[N];

int dfs(const string &node, int sum) {
  if (cnt[node]) return sum;

  int l = 0, h = sz - 1;
  while (l <= h) {
      int m = (l + h) / 2;
      if (depth[m] == node.size()) return sum += power26[node.size()];
      if (depth[m] < node.size()) l = m + 1;
      else h = m - 1;
  }

  return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        cin >> n;
        wildcards.clear();
        cnt.clear();
        for (int i = 1; i <= n; i++) {
            string x; cin >> x;
            wildcards.push_back(x);
        }
        sort(wildcards.begin(), wildcards.end());

        sz = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && wildcards[j][0] == wildcards[i][0]) j++;
            for (int l = 0; l < (int)wildcards[i].size(); l++) {
                string sub = wildcards[i].substr(0, l + 1);
                bool is_all_question = true;
                for (int k = i; k < j; k++) {
                    if (l >= wildcards[k].size() || wildcards[k][l] != '?')
                        is_all_question = false;
                }
                if (!is_all_question) {
                    depth[sz] = (int)sub.size();
                    cnt[sub] = is_all_question;
                    sz++;
                }
            }
            i = j - 1;
        }

        power26[0] = 1;
        for (int i = 1; i <= 26; i++) power26[i] = (power26[i - 1] * 26) % M;

        int ans = sz == 0 ? 1 : wildcards[sz - 1][wildcards[sz - 1].size() - 1] != '?';
        for (int i = 0; i < sz; i++) ans = (ans + dfs(wildcards[i], 1)) % M;

        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;
}
