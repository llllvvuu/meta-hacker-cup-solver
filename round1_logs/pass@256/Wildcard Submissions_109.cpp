
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
using namespace std;

const int mod = 998244353;
int power(int a, int p) {
    if (p == 0) return 1;
    int res = power(a, p / 2);
    res = (res * 1LL * res) % mod;
    if (p % 2) res = (res * 1LL * a) % mod;
    return res;
}

vector<int> trie;  // Index at root.
int combine(int a, int b) {
    return (1LL * a * b + b) % mod;  // Since each string can also form new unique nodes.
}

int insert(string s) {
    int node = 0;
    for (char c : s) {
        if (c == '?') {  // Represents branching out into all 26 possibilities.
            node = combine(node, power(26, s.size() - 1 - (s.find(c) == string::npos)));
        } else {  // New node.
            node = combine(node, node);
        }
    }
    return node;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (auto &s : S) cin >> s;

        int ans = 1;  // 1 for the empty prefix.
        for (auto &s : S) ans = (ans + insert(s) - 1 + mod) % mod;

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
