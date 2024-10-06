
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
#include <string>
#include <vector>

using namespace std;

const int MOD = 998244353;

struct Trie {
    int mask = 0;
    int cnt = 0;

    void add(int mask_) {
        if (mask == 0)
            mask = mask_;
        else
            mask = mask | mask_;
        cnt++;
    }

    static Trie merge(const Trie& a, const Trie& b) {
        Trie t;
        t.cnt = (a.cnt + b.cnt) % MOD;
        t.mask = a.mask | b.mask;
        return t;
    }
};

int T, N;
string S[30];
vector<Trie> dp[30][101];

Trie process(int idx, int len) {
    if (len == S[idx].size())
        return {};
    if (dp[idx][len].size() != 0)
        return dp[idx][len][len];
    Trie t = process(idx, len + 1);
    if (S[idx][len] == '?')
        return t;
    int bit = (1 << (S[idx][len] - 'A'));
    Trie res = { bit, 1 };
    res = Trie::merge(res, t);
    return dp[idx][len].push_back(res), res;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> S[i];
        dp[0][0].push_back({});
        for (int i = 0; i < N; i++)
            process(i, 0);
        Trie ans = {};
        for (int i = 0; i < N; i++)
            ans = Trie::merge(ans, dp[i][0][0]);
        cout << "Case #" << t << ": " << ans.cnt << endl;
    }
    return 0;
}
