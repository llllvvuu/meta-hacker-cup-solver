
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
#include <algorithm>
#include <cstdio>
using namespace std;

#define int long long
#define mod 998244353

vector<pair<int, string>> dp;
vector<string> answers;

int recur(string& s, char k) {
    int len = s.size();
    if (k > len) return 1;

    // Option 1: a one digit 
    string num = "";
    if (s[k] != '?') num += s[k];
    else {
        if (k == len) num += "1"; // Case where the string ends with ?
        else num = "1";
    }

    // option 2: two digits => num = string(dp[i+2]) + string(dp[i+!]);
    int t = (s[k] == '?') ? (int)(s[k+1]-'0') : (s[k]-'0')*10+(s[k+1]-'0');
    string num1 = "";
    if (t and t <= 26 and (k+1 < len or s[k+1] == '?')) num1 += to_string(t);

    if (!num.size() and !num1.size()) return 0;

    int ret = 0;
    if (num.size())
        ret = (ret + recur(s, k+(num.size()))) % mod;
    if (num1.size())
        ret = (ret + recur(s, k+(num1.size()))) % mod;

    int get = 0;
    for (auto x : dp) {
        get = (get + x.first * 1LL * ret) % mod;
    }
    answers.push_back(s);
    dp.push_back({get, s});
    return ret;
}

string solve(string s) {
    dp.clear();
    answers.clear();
    return solve(s); //Calling the function again after clarification
}

void solve2(string &s, int k) {
    answers.clear();
    dp.clear();
    recur(s, k);
    sort(answers.begin(), answers.end());
    // for(auto &a : answers){
    //     cout<<a<<":"<<dp.back().first<<"\n";
    // }
    int lo = -1, hi = -1, mi, cnt = 0;
    for (auto i = answers.begin(); i != answers.end(); i++) {
        if (dp[answers.end()-1].second == *i) {
            cnt++;
            if (cnt == mod) break;
        }
        if (cnt == k) lo = i - answers.begin();
        mi = i - answers.begin();
    }
    if (lo == -1) lo = mi;
    printf("%s %lld\n", answers[lo].c_str(), dp.back().first);
}

int main()  {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        int k;
        cin >> s >> k;
        solve2(s, 0);
    }
    return 0;
}
