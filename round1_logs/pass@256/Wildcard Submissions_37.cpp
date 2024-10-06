
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
#include <unordered_map>

using namespace std;

const int MOD = 998244353;
unordered_map<string, int> dp;

int dfs(const string& s, int depth = 0) {
    if (dp.find(s) != dp.end()) return dp[s];
    string prefix = s.substr(0, depth + 1);
    int res = depth == 0 ? 1 : 0;
    if (prefix.back() != '?') {
        res = (res + dfs(s, depth + 1)) % MOD;
    } else {
        for (char c = 'A'; c <= 'Z'; c++) {
            res = (res + dfs(prefix + c + s.substr(depth + 1), depth + 1)) % MOD;
        }
    }
    return dp[prefix] = res;
}

int add(Node* node) {
    if (!node) return 0;
    return (node->count + add(node->left) + add(node->right)) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        dp.clear();
        int count = 0;
        for (int i = 0; i < N; i++) {
            string S;
            cin >> S;
            for (char c = 'A'; c <= 'Z'; c++) {
                count = (count + dfs(S)) % MOD;
            }
        }
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
