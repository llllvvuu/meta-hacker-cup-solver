
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

int ncr[30][101] = {0};
int letters = 26;

// Function to compute combinations relevant for our algorithm
void precompute() {
    for (int k = 0; k <= 25; k++) {
        ncr[k][0] = 1; ncr[k][k] = 1;
        for (int j = 1; j < k; j++) 
            ncr[k][j] = (ncr[k-1][j-1] + ncr[k-1][j]) % 998244353;
    }
}

// Function to count nodes given a wildcard string `WC[1..W]`
int val(char *WC, int W) {
    long long val = 0;
    int ct = 0;
    for (int j = 1; j <= W; j++) {
        if (WC[j] == '?') {
            val = (val + ncr[letters][ct+1]) % 998244353;
        } else {
            ct++;
            val = (val + ncr[letters][ct]) % 998244353;
        }
    }
    return val;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    precompute();
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n; cin >> n;
        long long total = 0;
        for (int j = 0; j < n; j++) {
            char WC[105];
            cin >> WC;
            int w = strlen(WC+1);
            total = (total + val(WC, w)) % 998244353;
        }
        cout << "Case #" << i << ": " << total << "\n";
    }
}
