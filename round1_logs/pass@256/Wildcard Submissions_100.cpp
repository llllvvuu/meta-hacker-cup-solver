
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

const int MAXLEN = 105;
const int MOD = 998244353;

int n;
string s[MAXLEN];
int count[MAXLEN][26];
int dp[MAXLEN][MAXLEN];

// Node is its position in the word, depth is how many letters are its prefix, and count is max up to that point.
int solve(int node, int depth) {
    if (node == n) return 0;
    int &ret = dp[node][depth];
    if (ret != -1) return ret;
    ret = 0;

    // Consider the string from this point to the end
    for (int end = node; end < n && end-depth < s[node].size(); end++) {
        // ? is a wild card, so we allow all 26 characters here
        int currCount = (s[node][end-depth] == '?' ? 26 : 1);
        ret += currCount;
        if (currCount * count[end-depth+1][s[node][end-depth]-'A'] == 0) ret++;
        ret %= MOD;

        // Move to the next round where we will consider the next letters as prefix starting point
        (count[depth+1][s[node][end-depth]-'A'] += currCount) %= MOD;
    }
    for (int i = 0; i < 26; ++i)
        count[depth][i] = max(count[depth][i], count[depth+1][i]);
 
    // Recursively call the function for the next node
    return ret = (ret + solve(node + 1, depth)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for (int w = 1; w <= t; ++w) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];

        // Reset count and dp
        memset(count, 0, sizeof(count));
        memset(dp, -1, sizeof(dp));
        cout << "Case #" << w << ": " << (solve(0, 0) + 1) % MOD << "\n";
    }
}
