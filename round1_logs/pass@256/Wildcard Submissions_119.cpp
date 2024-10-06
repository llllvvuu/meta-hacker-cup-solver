
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
struct TrieNode {
    TrieNode *next[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) 
            next[i] = nullptr;
    }
};

TrieNode root;
int MOD = 998244353;
char arr[27];

int dfs(TrieNode *node, int llen) {
    if (llen < 0) 
        return 1;
    int ans = 1;
    for (int i = 0; i < 26; i++) {
        if (node->next[i])
            ans = (ans + dfs(node->next[i], llen - 1)) % MOD;
    }
    return ans;
}

int split(TrieNode *node, string &w, int start, int llen, vector<pair<int,int>> &q) {
    if (start == w.length()) 
        return llen;

    int nd = 26;
    for (int i = 0; i < 26; i++) 
        if (node->next[i]) nd = 0;
    if (nd && w[start] != '?') {
        int c = w[start] - 'A';
        if (!node->next[c]) 
            node->next[c] = new TrieNode();
        return split(node->next[c], w, start + 1, llen - 1, q);
    }

    q.push_back({llen, start});

    return llen;
}

int main() {
 
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {

        int N;
        cin >> N;

        vector<string> warr(N);
        for(int i = 0; i < N; i++) cin >> warr[i];

        vector<vector<int>> Q;
        for (int i = 0; i < N; i++) {
            int llen = warr[i].length();
            if (llen == 0) Q.push_back({});
            if (llen == 1) {
                Q.push_back({'?', i});
                break;
            } else {
                vector<pair<int, int>> q;
                split(&root, warr[i], 0, llen, q);
                Q.push_back(q);
            }
        }
        
        vector<vector<int>> M(Q.size(), vector<int>(27, 0));

        long long ans = dfs(&root, -1); // count the root node
        
        int cnt = 0;
        for (int i = 0; i < Q.size(); i++) {
            for (auto &t: Q[i]) {
                for (int i = 0; i <= t.second; i++) { 
                    M[i][t.first-1] += M[i][26];
                    M[i+1][26] = (M[i][26] - M[i][t.first-1]);
                    if (i > 0)
                        M[i+1][26] = (M[i+1][26] + cnt * M[i][t.first-1]) % MOD;
                    M[i][26] = 0;
                }
                M[t.second+1][t.first-1]++;
                cnt++;
            }
            for (int i = 0; i < M[i].size(); i++) 
                if (M[i][26])
                    ans = (ans + M[i][26]) % MOD;
        }
        
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
