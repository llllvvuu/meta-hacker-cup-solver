
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
#include <string>
using namespace std;

const int MOD = 998244353;

int solve(string_view str, const int k, vector<int>& dp, string_view template_str) {
    dp[0] = 1;
    int max_val = 0;
    vector<pair<int, string>> answers{{{0, ""}}};

    for (int i = 0; i < template_str.size(); i++) {
        int val = template_str[i] == '?' ? -1 : template_str[i] - '0';
        string str = to_string(val);
        dp[i + 1] = (dp[i] + dp[max(i - 2, 0)] * (0 <= val && val <= 26)) % MOD;
        for (auto& p : answers) p.first = (p.first + dp[i] + dp[max(i - 2, 0)] * (0 <= val && val <= 26) - p.second.size()) % MOD;
        if (dp[i] + dp[max(i - 2, 0)] * (0 <= val && val <= 26) > max_val) {
            answers.clear();
            max_val = dp[i + 1];
            answers = {{max_val, str}};
        } else if (dp[i] + dp[max(i - 2, 0)] * (0 <= val && val <= 26) == max_val) {
            answers.push_back({max_val, str});
        }
    }
    auto it = answers.begin() + min(answers.size(), k) - 1;
    if (it != answers.end()) sort(answers.begin(), it + 1);
    return it != answers.end() ? answers[it - answers.begin()].second : string();
}

int main() {
    int t;
    cin >> t;
    for (int caseIdx = 1; caseIdx <= t; caseIdx++) {
        string input;
        int k;
        cin >> input >> k;
        vector<int> dp(input.size() + 1, 0);
        sort(input.begin(), input.end());
        string output = solve(input, k, dp, input);
        cout << "Case #" << caseIdx << ": " << output << ' ' << dp[input.size()] << endl;
    }
    return 0;
}
