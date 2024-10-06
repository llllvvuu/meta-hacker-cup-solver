
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
#include <array>
#include <climits>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

const ll maxN = 105, mod = 998'244'353;
int N, T;
vector<string> S(maxN);
vector<char> ch = {'X', 'Y', 'Z'};

// Hash table for all configurations
map<vector<int>, ll> table;

// Generate the unique key for a given configuration of 26 chars and 3 ?
void genKey(vector<int> &arr) {
    ll hash = 0, p = 1;
    for (int i = 0; i < 29; i++) {
        hash += (arr[i] * p) % mod;
        p = (p * 29) % mod;
    }
    arr[29] = hash;
}

// Find the sum of nodes based on configuration
ll get(vector<int> &arr) {
    genKey(arr);
    return table[arr];
}

// Update table with a configuration
void push(vector<int> &arr) {
    genKey(arr);
    table[arr]++;
}

void solve(int t) {
    cin >> N;
    table.clear();
    push({});
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        map<ll, ll> cnt;
        for (int j = 0; j < 26; j++)
            cnt[j] = get(table);
        for (int j = 0; j < 3; j++)
            cnt[ch[j]-'A'] += get(table);

        for (int j = 0; j < S[i].size(); j++) {
            char ch = S[i][j];
            vector<int> next(29, 29);
            if (ch >= 'A' && ch <= 'Z') {
                next[ch-'A'] = ch - 'A';
            } else if (ch >= 'X' && ch <= 'Z') {
                next[ch-'X'] = ch - 'A';
            }
            next[28] = 28;

            for (auto [c, v]: cnt) {
                if (c == 28) c = 29;

                if (v == 0) continue;
                vector<int> cur(29, c);
                cur[28] = 29;
                cur[29] = 0;
                if (next[28] == 29)
                    v = (v * 29) % mod;

                ll sum = get(cur);
                push(cur);
                cnt[c] = (cnt[c] - sum + v) % mod;
                if (sum > 0)
                    cnt[next[next[ch - 'A']]] = (cnt[next[next[ch - 'A']]] + sum) % mod;
            }
        }
    }

    cout << "Case #" << t << ": " << (get({}) + mod - 1) % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++)
        solve(t);
}
