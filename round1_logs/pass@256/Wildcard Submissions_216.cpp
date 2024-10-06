
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
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

typedef long long ll;

const ll MOD = 998244353;
const ll MAXP = 100;
const ll BASE = 13331;
const ll BASE_INV = 834025808; // Multiplicative inverse of BASE

unordered_set<ll> seen;
ll pressed[MAXP + 1]; // Keep track of seen prefixes
ll pows[MAXP + 1] = {1};

void precalc() {
    for (int i = 1; i <= MAXP; i++) {
        pows[i] = (pows[i - 1] * BASE) % MOD;
    }
}

void hash_add(ll& h, char c) {
    h = (h * BASE + c) % MOD;
    pressed[h] = 1;
}

ll dfs(const string& s, int i, ll base_hash) {
    if (seen.count(base_hash)) return 0;
    seen.insert(base_hash);
    
    ll result = 1; // For the base_hash itself
    if (i < s.size()) {
        const ll len = s.size() - i;
        for (char c = 'A'; c <= 'Z'; c++) {
            ll new_hash = (base_hash + pows[len - 1] * c) % MOD;
            if (seen.count(new_hash)) continue;
            if (c == '?') {
                pressed[new_hash] = 0;
            } else {
                hash_add(new_hash, c);
            }
            result += dfs(s, i + 1, new_hash);
            result %= MOD;
            if (c == '?') pressed[new_hash] = 1;
        }
    }
    seen.erase(base_hash);
    return result;
}

int main() {
    precalc();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        seen.clear();
        ll result = 0;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            hash_add(0, ' ');
            result += dfs(s, 0, 0);
            result %= MOD;
        }
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
