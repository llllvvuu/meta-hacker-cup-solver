
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
using namespace std;

// Function to get the Kth largest string and its decoding count
pair<string, int> calculateAcc(string s, int k) {
    vector<long long> dp(s.size(), 1);
    vector<string> paths(s.size());
    
    // dp[i][0] = all possible continuations, dp[i][1] = the lexicographical path
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            s[i] = '1';
        }
        dp[i] = 1;
        for (int j = i + 1; j < s.size(); j++) { 
            if (s[j] == '?') 
                s[j] = '1';
            if (dp[j] == 0)
                continue;
            int num = stoi(s.substr(i, j - i + 1));
            if (num > 0 && num < 100 && (num < 27 || s[i] != '1' || s[j] != '0')) { 
                if (j - i >= 1)
                    dp[i] += dp[j + 1];
                if (dp[j + 1] > 0) {
                    paths[i] += s.substr(i, j - i + 1) + ">";
                }
            }
        }
    }
    
    vector<pair<string, int>> res = {{"", 0}};
    for (auto&P : paths) {
        string tmp = P;
        int i = 0;
        while (i < tmp.size() && tmp[i] != '>') {
            s[i] = '?';
            tmp.erase(tmp.begin() + i);
            i++;
        }
        string t ("");

        auto x = tmp.size();
        for (int i = 0; i < x; i++)
            t += s[i];
        int sum = x + res.back().second;
        if (sum >= k)
            res.push_back({t, sum});
        while (i < tmp.size())
            s[i] = '1';
    }
    
    return {res.back().first, res.back().second % 998244353};
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        string s; int k;
        cin >> s >> k;
        s = ' ' + s;
        auto pr = calculateAcc(s, k);
        cout << "Case #" << i << ": " << pr.first << " " << pr.second << endl;
    }
    return 0;
}
