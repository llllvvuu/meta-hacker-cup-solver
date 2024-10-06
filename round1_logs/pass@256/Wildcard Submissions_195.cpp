
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
const int MAX_S = 105;
const int MAX_N = 25;
const char ALPHABET_SIZE = 26;
const int MOD = 998244353;

int dp[MAX_S] = {};

void resize(int N) {
    for (int i = 0 ; i < N ; i++) dp[i + 1] = 0;
    dp[1] = 1;
}

void processPattern(const string& pattern, int N) {
    size_t len = pattern.size();
    for (size_t i = len ; i >= 1 ; i--) {
        int oldVal = dp[i + 1] % MOD;
        dp[i + 1] = (dp[i] * (((pattern[len - i] == '?') ? ALPHABET_SIZE : 1) + oldVal)) % MOD;
    }
}

void processWildcards(const vector<string>& wildcards, int N) {
    for (const auto& pattern : wildcards) {
        processPattern(pattern, N);
    }
}

void processQuery(const vector<string>& wildcards) {
    int N = *max_element(wildcards.begin(), wildcards.end(), [](const string& s1, const string& s2) {
        return s1.size() < s2.size();
    });
    resize(N);
    processWildcards(wildcards, N);
    int result = dp[N + 1];
    for (int i = 1; i < N + 1; i++) {
        result = (result - dp[i] + MOD) % MOD;
    }
    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int numWildcards;
        cin >> numWildcards;
        vector<string> wildcards(numWildcards);
        for (int i = 0 ; i < numWildcards ; i++) cin >> wildcards[i];
        cout << "Case #" << t << ": ";
        processQuery(wildcards);
    }
    return 0;
}
