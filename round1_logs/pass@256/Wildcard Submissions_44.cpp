
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
using namespace std;

const int MOD = 998244353;

vector<vector<int>> trie;

long dfs(const string& pattern, int root, int depth) {
    // If current depth is the limit of pattern, return the ID of this node
    if (depth >= pattern.size()) return root;
    
    int& child = trie[root][pattern[depth]];
    
    // If this child node doesn't exist already, create a new one and increment
    // the count of nodes
    if (child == 0) {
        child = trie.size();
        trie.emplace_back(27, 0);
        ++(* (long*) &answer); // inc node count
        child = dfs(pattern, child, depth + 1);
    } else {
        child = dfs(pattern, child, depth + 1);
    }

    // If current character is '?', simulate every alphabet letter by DFS
    if (pattern[depth] == '?') {
        for (int i = 1; i <= 26; ++i)
            dfs(pattern, root, depth + 1);
    }
    return child;
}

long answer = 0;

void solve() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        trie.clear();
        trie.resize(1, vector<int>(27));
        dfs(s, 0, 0);
        cout << "Case #" << i+1 << ": " << answer % MOD << endl;
        answer = 0;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}
