
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
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
using namespace std;

long MOD = 998244353;

unordered_set<string> full;
unordered_map<string, pair<string, int>> memo;

pair<string, int> solve(string s) {
    if (memo.count(s)) return memo[s];
    if (s.size() == 1) return memo[s] = {s, 1};
    string key = s.substr(0, s.size() - 1);
    pair<string, int> have = memo[key];
    if (have.first.empty()) have = solve(key);
    string store = have.first;
    int count = have.second;
    char next = s.back();
    if (next == '?') {
        for (auto itr = 'A'; itr <= 'Z'; itr++) {
            store += itr;
            count++;
            auto pair = solve(store);
            count += pair.second - 1;
            count %= MOD;
            store.pop_back();
        }
    } else {
        store += next;
        full.insert(store);
        count++;
    }
    return memo[s] = {store, count};
}

int main() {
    assert(solve("X?").second == 27);
    assert(solve("?").second == 26);
    assert(solve("??M?".second == 26*26*27));

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        while (!full.empty()) full.erase(full.begin());
        for (int i = 0; i < N; i++) {
            string s; cin >> s;
            while (!memo.empty()) memo.erase(memo.begin());
            full.insert(s);
            string peterPrefix = memo[""].first;
            auto pair = solve(peterPrefix);
        }
        vector<string> toOrigin(full.begin(), full.end());
        long sum = 1;
        sort(toOrigin.begin(), toOrigin.end());
        string prefix = "";
        for (auto s : toOrigin) {
            if (prefix == s) continue;
            int diffLen = s.size() - prefix.size();
            prefix = s;
            sum = (sum + diffLen) % MOD;
        }
        cout << "Case #" << t << ": " << sum  << "\n";
    }
    return 0;
}
