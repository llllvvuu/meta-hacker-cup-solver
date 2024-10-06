
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

const int MOD = 998244353;

int T;
long long W, G, L;
map<pair<long long, long long>, long long> DP;

long long solve(long long w, long long l) {
    if (w <= l) return 0;
    if (l >= G) {
        if (w == G) return 0;
        else return (1 + solve(w - 1, l));
    }
    if (DP.find({w,l}) != DP.end()) return DP[{w, l}];
    long long res = (1 + (solve(w - 1, l) + solve(min(w + 1, l + L), l)) % MOD) % MOD;
    DP[{w, l}] = res;
    return res;
}

pair<long long, long long> solve(int tc) {
    if (W <= G + L) return {W - G, 1};
    long long days = solve(W, W);
    long long den = 1, num = days;
    den = 1;
    for (int i = 0; i < MOD - 2; i++) {
        num = (num * num) % MOD;
        den = (den * den) % MOD;
    }
    num = (num * 2) % MOD;
    den = (den * 2) % MOD;
    return {num, den};
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> W >> G >> L; DP.clear();
        pair<long long, long long> ans = solve(i);
        cout << "Case #" << i << ": " << ans.first * ans.second % MOD << endl;
    }
    return 0;
}
