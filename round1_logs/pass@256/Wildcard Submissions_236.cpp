
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
#include <string>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int ALPHABET_SIZE = 26;

string S[26];

int dp[26][2];

// Recursive function to compute the number of nodes in the trie
int solve(int i, int r) {
    int &ans = dp[i][r];
    if (ans != -1) return ans;
    if (i == S[i].length()) return r ? 1 : 0;
    ans = 0;
    if (S[i][i] == '?') {
        for (char c = 'A'; c <= 'Z'; c++) {
            ans += solve(i + 1, 0) + solve(i + 1, 1);
            ans %= MOD;
        }
        ans += solve(i + 1, r);
    } else {
        ans += solve(i + 1, 0);
    }
    return ans % MOD;
}

void process_case(const int tc) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int answer = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        answer += solve(0, 1);
        answer %= MOD;
    }
    cout << "Case #" << tc << ": " << answer << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        process_case(t);
    }
    return 0;
}
