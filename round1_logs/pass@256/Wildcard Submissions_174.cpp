
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
#include <cassert>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;

const int PRIME = 998244353;
long count_wildcard(const string &w) {
    map<vector<long>, long> node_map;
    vector<bool> seen;
    long node_count = 0, res;

    function<void(const string &, long, long)> recurse = [&](const string& s, long length, long node_id) {
        if (length == w.size()) {
            node_count = (node_count + node_id) % PRIME;
            return;
        }
        auto& sub_map = node_map[node_id];
        if (!sub_map.empty()) {
            for (auto pair : sub_map) {
                recurse(s.substr(0, length) + w[length], pair.first, pair.second);
            }
        } else {
            seen.resize(max(seen.size(), length + 1));
            for (char c = 'A'; c <= 'Z'; c++) {
                string current = s;
                if (seen[length] || w[length] == '?')
                    current[length] = c;
                if (current == s)
                    continue;
                long next_id;
                auto it = sub_map.find(next_id = (node_id * 26 + c));
                if (it == sub_map.end()) {
                    sub_map[next_id] = next_id + node_id;
                    node_count = (node_count + next_id + node_id) % PRIME;
                    seen[length] = true;
                }
                recurse(current, length + 1, next_id);
            }
        }
    };
    
    recurse("", 0, 0);
    return node_count;
}

void solve() {
    int n;
    cin >> n;
    vector<string> wildcards(n);
    for (auto &s : wildcards) {
        cin >> s;
    }
    long total = 0;
    for (auto s : wildcards) {
        total = (total + count_wildcard(s)) % PRIME;
    }
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
