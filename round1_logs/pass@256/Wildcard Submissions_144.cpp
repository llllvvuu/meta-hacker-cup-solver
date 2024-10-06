
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
#include <cassert>
using namespace std;

const int M = 998244353;

// Define a Type for storing the state of DFS
using State = tuple<int, int, bool>;

// DFS function to count nodes
unordered_map<State, int, hash<State>> dp;
int dfs(vector<vector<string>>& trie, int level = 1, int question_count = 0, bool can_skip = true) {
    auto key = State(level, question_count, can_skip);
    if (dp.find(key) != dp.end()) {
        return dp[key];
    }
    if (level > trie.size()) {
        return 0; // Out of bounds index
    }
    long res = can_skip ? dfs(trie, level + 1) : 0;
    long alphabet_size = can_skip ? 26 : 1;
    long current_question_gibson = question_count > 0 ? static_cast<long>(pow(26, question_count)) - 25 : 1;
    for (const string& subtree : trie[level]) {
        if (subtree.empty()) {
            continue;
        }
        vector<vector<string>> deeper_trie = get_deeper_trie(subtree);
        for (int i = 0; i < subtree.size(); ++i) {
            res += dfs(deeper_trie, i + level + 1, 0, alphabet_size == 26) % M;
        }
        if (question_count == 0) {
            continue;
        }
    }
    return dp[key] = res % M;
}

vector<vector<string>> get_deeper_trie(const string& str) {
    vector<vector<string>> trie(str.size() - 1);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '?') {
            int len = 0;
            while (i < str.size() && str[i] == '?') {
                i++;
                len++;
            }
            for (int q = 0; q < len; q++) {
                if (i < str.size() && str[i] != '?') {
                    trie[len - q - 1].push_back(str[i] + string(len - q - 1, '?'));
                }
            }
            i--;
        }
    }
    return trie;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        dp.clear();
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        auto trie = get_deeper_trie(string(S[0]));

        for (int i = 1; i < N; i++) {
            auto new_trie = get_deeper_trie(S[i]);
            auto deeper_trie = get_deeper_trie(string(S[i]));
            for (int j = 0; j < min((int)trie.size(), (int)new_trie.size()); j++) {
                trie[j].insert(trie[j].end(), new_trie[j].begin(), new_trie[j].end());
            }
            for (int j = max((int)trie.size(), (int)new_trie.size()); j < max(S[i].size(), S[0].size()); j++) {
                trie.push_back((j < S[i].size() ? new_trie[j] : {}));
            }
        }
        // Rebuild the trie to reflect common information
        cout << (dfs(trie) + 1) % M << "\n"; // Add 1 for the root node
    }
    return 0;
}
