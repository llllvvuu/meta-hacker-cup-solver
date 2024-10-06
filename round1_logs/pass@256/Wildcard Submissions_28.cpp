
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
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
using namespace std;

constexpr int MOD = 998244353;
map<int, vector<int>> trie; // bitmasks to children based on (bitmask & 26)
int sz; // current number of nodes in the trie

void insert(set<int>& nodes, unsigned mask__, int node) {
    if (node == -1) {
        auto insert_res = nodes.insert(mask__);
        if (insert_res.second)
            sz++;
        return;
    }
    for (int i = 0; i < 26; i++) {
        insert(nodes, (mask__ | (1 << i)), trie[node][i]);
    }
}

int solve(const string& S) {
    int cnt = 0;
    set<int> nodes;
    for (int i = 0; i < (1<<26); i++) { // iterate over all possible bitmasks 
        int mask = i, node = 0;
        bool is_within_range = true;
        for (char c : S) {
            if (c == '?') {
                for (int char_i = 0; char_i < 26; char_i++) {
                    auto char_c = 'A' + char_i;
                    if ((mask & (1 << char_i))) {
                        is_within_range &= (S[2] != char_c); // adjust for actual problem constraints
                        insert(nodes, mask, node);
                    }
                }
            } else {
                node = trie[node][c - 'A'];
                if (node == -1 || (mask & (1 << (c - 'A')))) {
                    is_within_range = false;
                    break;
                }
                mask |= (1 << (c - 'A'));
            }
            if (!is_within_range) break;
        }
        if (is_within_range) {
            insert(nodes, mask, node);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        for (int i = 0; i <= (1 << 26); i++) {
            trie[i].resize(26, -1); // empty initialization
        }
        sz = 1;
        string S;
        for (int i = 0; i < N; i++) {
            cin >> S;
            // Special case handling for shorter wildcard strings
            if (S.size() < 2) {
                set<int> nodes;
                nodes.insert(0); // root
                for (char c : S) {
                    if (c != '?')
                        nodes.insert(nodes.size() + ('A' - S[1]) * 4 + 2 * (S[0] - 'A'));
                }
                insert(nodes, 0);
                sz = nodes.size();
                trie[0][S[0] - 'A'] = 1;
            } else {
                for (char c : S) {
                    if (c != '?') {
                        trie[0][(c - 'A')].resize(26, -1);
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << (sz % MOD) << endl;
    }
    return 0;
}
