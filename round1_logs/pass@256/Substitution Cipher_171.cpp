
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
using namespace std;
#include <string>

long long MOD = 998244353;

struct Node {
    string s;
    long long count;

    bool operator<(const Node &other) const {
        if (count == other.count) return s > other.s;
        return count < other.count;
    }
};

struct compare {
    bool operator()(const Node &a, const Node &b) const {
        if (a.count != b.count) return a.count < b.count;
        return a.s < b.s;
    }
};

string solve_kth_largest_decodable_string(const string &s, int k) {
    map<string, long long> dp_s;
    map<long long, set<string>> dp_count;
    set<Node, compare> mp;

    dp_s[s] = 1;
    dp_count[1] = {s};
    vector<string> ans;

    for (const auto &itr : dp_count) {
        for (string x : itr.second) {
            int n = x.size();
            for (int i = 0; i < n; i++) {
                if (isdigit(x[i])) {
                    string sub_string = x.substr(0, i) + x.substr(i + 1, n - i - 1);
                    if (sub_string == "") continue;
                    dp_s[sub_string]++;
                    if (dp_s[sub_string] == 1)
                        mp.insert({sub_string, 1});
                    else
                        mp.insert({sub_string, dp_s[sub_string]});
                    dp_count[dp_s[sub_string]].insert(sub_string);
                } else {
                    for (int j = 1; j < 10; j++) {
                        if ((i == 0 && j == 0) || stoi(x.substr(i, i + 1)) > 26) continue;
                        char add = '0' + j;
                        string sub_string = x.substr(0, i) + string(1, add) + x.substr(i + 1, n - i - 1);
                        dp_s[sub_string]++;
                        if (dp_s[sub_string] == 1)
                            mp.insert({sub_string, 1});
                        else
                            mp.insert({sub_string, dp_s[sub_string]});
                        dp_count[dp_s[sub_string]].insert(sub_string);
                    }
                }
            }
        }
        if (k <= mp.size()) break;
    }

    int i = 1;
    for (auto &pair : mp) {
        if (i == k) {
            string s = pair.s;
            long long count = pair.count;
            s = s;
            return s + " " + to_string(count % MOD);
        }
        i++;
    }

    return "0 0";
}

int main() {
    int T, t = 1;
    cin >> T;
    while (T--) {
        string E, ans_s;
        long long ans_c;
        cin >> E >> ans_s, cin >> ans_c;
        ans = solve_kth_largest_decodable_string(E, stoi(ans_s));
        cout << "Case #" << t << ": " << ans << endl;
        t++;
    }
    return 0;
}
