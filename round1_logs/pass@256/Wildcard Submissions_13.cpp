
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
#include <string>
#include <set>
#include <vector>
using namespace std;

string to_str(const set<char>& s) {
    char rep[30];
    memset(rep, 0, sizeof(rep));
    for (auto ch : s) rep[ch - 'A'] = 1;
    return string(rep);
}

vector<int> solve() {
    int N, cnt[101] = {}, ans = 1;
    cin >> N;
    vector<string> queries(N);
    for (auto& q : queries) cin >> q;
    set<char> seen;
    for (char c : queries[0][0]) seen.insert(c);
    ans = 1 + seen.size();
    cnt[0] = seen.size();
    for (int col = 1; col < 100; col++) {
        for (int i = 0; i < N; i++) {
            if (col < queries[i].size() && queries[i][col] != '?')
                seen.insert(queries[i][col]);
        }
        int mod = 998244353;
        ans = (ans + ((long long)cnt[col - 1] * seen.size()) % mod) % mod;
        cnt[col] = seen.size();
        seen.clear();
    }
    return {ans};
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        vector<int> result = solve();
        cout << result[0] << endl;
    }
    return 0;
}
