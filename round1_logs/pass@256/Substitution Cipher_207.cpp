
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
#include <algorithm>
#include <cassert>
using namespace std;

int mod = 998244353;
vector<string> decodeMax(string e, int k) {
    // Implement your approach
    // Generates all possible uncorrupted strings, treating each '?' as a node in a tree
    // branch to left or right node representing 0..9
    // collects strings into structured dynamic programming format
    // delegates computing number of encoded strings to worker function
}

pair<string ,int > solve(int test_index, string e, int k) {
    vector<string> solutions = decodeMax(e, k); // uncorrupted strings // added constraint function
    sort(solutions.begin(), solutions.end()); // lexi sort

    // find the kth largest solution (Lastly checks for multiple solutions with max decoded strings)
    for (int maxDecoded = 0; k--; ) {
        int decoded = decodeCount(solutions[maxDecoded]);
        while (maxDecoded < solutions.size() && decodeCount(solutions[maxDecoded]) == decoded)
            maxDecoded++;
    }

    return make_pair(solutions[maxDecoded - 1], decodeCount(solutions[maxDecoded - 1]) % mod);
}

int decodeCount(string corr_e) {
    vector<int> dp(corr_e.length() + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= corr_e.length(); i++) {
        if (corr_e[i - 1] == '0') dp[i] = 0;
        else {
            dp[i] = dp[i - 1];
            if (i >= 2 and corr_e[i - 2] != '0' and stoi(corr_e.substr(i - 2, 2)) <= 26) dp[i] = (dp[i] + dp[i - 2]) % mod;
        }
    }
    return dp.back();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string encoded;
        int k;
        cin >> encoded >> k;
        const auto [result_str, decoded_count] = solve(t, encoded, k);
        cout << "Case #" << t << ": " << result_str << " " << decoded_count << endl;
    }
    return 0;
}
