
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
using namespace std;
const int MAXS = 102, MOD = 998244353;
struct Trie {
    static constexpr int intInit = -1;
    vector<pair<int,int>> nodes(MAXS * 26, {intInit, intInit});
    vector<vector<int>> back(MAXS * 26);
    Trie() { nodes[0] = {0, 0}; }
    int addStr(const string &str) {
        int p = 0;
        for (auto c: str) {
            if (nodes[p].first == intInit || c != '?') {
                const int last = static_cast<int>(back.size());
                back.emplace_back(p);
                if (c != '?') {
                    nodes.emplace_back(p, c - 'A');
                    p = last + 1;
                }
            } else {
                const int id1 = nodes[p].second > intInit ? nodes[p].second : last;
                const int id2 = last + (nodes[p].second == intInit ? 1 : 0);
                p = max(0, min(id2, nodes[id1].first < 0 ? id2-1 : id1) + 1);
            }
        }
        return p;
    }
    int countNodes() const {
        map<int, vector<int>> group;
        for (int i = 0; i < static_cast<int>(nodes.size()); i++) {
            if (nodes[i].first != intInit) {
                group[nodes[i].first].push_back(i);
            }
        }
        int res = group[0].size();
        for (const auto &p: group) {
            if (p.first == 0) { continue; }
            res += p.second.size();
            ++res;
        }
        res %= MOD;
        return res;
    }
};
int solve() {
    int n;
    string s;
    cin >> n;
    Trie trie;
    for (int i = 0; i < n; i++) {
        cin >> s;
        trie.addStr(s);
    }
    return trie.countNodes();
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
