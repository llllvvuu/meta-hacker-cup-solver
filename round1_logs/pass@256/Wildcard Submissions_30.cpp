
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

const int base = 26;
const int endl = '\n';
const int MOD = 998244353;

bool ar[101][base];

int dfs(int idx, int cur) {
    int& res = ar[idx][cur];
    if (res != -1) return res;
    res = cur;
    for (int i = 0; i < base; ++i) {
        res = (res + dfs(idx + 1, (cur * base + i) % MOD)) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int t, n, q;
    string s;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        int res = 1;
        fill(ar[0], ar[101], vector<bool>(base, -1));
        for (int j = 0; j < n; ++j) {
            cin >> s;
            q = 0;
            for (int k = 0; k < s.size(); ++k) {
                if (s[k] == '?') q += 1;
                else {
                    int c = s[k] - 'A';
                    res = (res + dfs(k + 1, q * base + c) % MOD) % MOD;
                    q *= base;
                }
            }
            if (q > 0) res = (res + dfs((int)(s.size()), q) % MOD) % MOD;           
        }
        cout << "Case #" << i << ": " << res << endl;
    }

    return 0;
}
