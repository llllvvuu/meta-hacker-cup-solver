
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
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

const int mod = 998244353;

// Helper function to convert a char to an int with 'A' as 0 and 'Z' as 25
int toInt(char c) {
    return c - 'A';
}

// Brute force way
unordered_set<string> brute_force(string s) {
    int last = s.length();
    s.erase(remove(s.begin(), s.end(), '?'), s.end());
    string p = "", t = s;
    for (int i = 0; i < last; ++i) {
        p += "A";
        while (t.length() < p.length() || !t.empty() && t.begin()[p.length()] > p[p.length()]) 
            p[p.length()] = (p[p.length()] < 'Z' ? p[p.length()]+1 : 'A');
        brute_force.insert(p);
    }
    return brute_force;
}

// Efficient method using bit manipulation
int process_string(const string& s, vector<map<int, int>>& dp) {
    dp[0][0] = 1; // Base case: empty string matches the root node
    for (const char& c : s) {
        vector<map<int, int>> ndp = dp;
        for (const auto& [mask, count] : dp) {
            if (c == '?') {
                fill(begin(ndp.back()), end(ndp.back()), 0);
                for (int l = 0; l < ndp.size(); l++) {
                    for (int m = 0; m < (1 << 26); m++) {
                        if (mask >> m & 1) ndp[l][mask].addMod(mod);
                        ndp[l + 1][mask + (1 << m)] = (ndp[l + 1][mask + (1 << m)] + count) % mod;
                    }
                }
            } else {
                ndp[1][mask + (1 << toInt(c))].addMod(mod);
            }
        }
        swap(dp, ndp);
    }
    int sum = 0;
    for (const auto& [_, count] : dp.back()) sum = (sum + count) % mod;
    return sum;
}

int main() {
    int T, N;
    string S;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N;
        vector<string> vec(N);
        for (int i = 0; i < N; ++i) cin >> vec[i];
        vector<map<int, int>> dp(vec[0].length() + 1);
        long long result = 0;
        for (const auto& s : vec) {
            result = (result + process_string(s, dp)) % mod;
        }
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
