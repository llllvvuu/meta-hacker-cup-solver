
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
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
const int MOD = 998244353;
vector<string> patterns;
unordered_set<int> trie;
int cnt;

void dfs(string cur, int idx) {
    if (idx == patterns.size()) {
        trie.insert(hashing(cur));
        return;
    }
    dfs(cur, idx + 1);  // Skip '?'.
    if (patterns[idx] == '?') {
        for (char c = 'A'; c <= 'Z'; ++c) {
            dfs(cur + c, idx + 1);
        }
    } else {
        dfs(cur + patterns[idx], idx + 1);
    }
}

int hashing(const string &s) {
    const int B = 17;
    int result = 0;
    for (auto c : s) {
        result = (result * B + c - 'A' + 1) % MOD;
    }
    return result;
}

unsigned long long solve(vector<string> S) {
    trie.clear();
    patterns = S;
    dfs("", 0);
    unordered_set<int>::iterator it;
    cnt = 0;
    for(it=trie.begin(); it!=trie.end(); ++it) {
        ++cnt;
    }
    return cnt % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for(int i = 0; i < N; i++) cin >> S[i];
        cout << "Case #" << t << ": " << solve(S) << endl;
    }
}
