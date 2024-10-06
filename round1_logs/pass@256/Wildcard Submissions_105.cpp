
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
#include <set>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N; cin >> N;
        set<string> prefixes; // Stores all unique prefixes
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            int sub = 0; // Stores substrings with at least one '?' removed
            for (int j = 0; j <= min(25, s.size()); j++) {
                vector<string> substrings; // Stores all unique substrings of s_j
                for (int k = j; k <= s.size(); k++) {
                    if (s[k] == '?') {
                        if (sub < j) { // If at least one '?' has been removed
                            sub++; // Counting substrings with one '?' removed
                            int shift = sub > 1; // For substrings with more '?'
                            for (int q = 0; q < 26-shift; q++) {
                                substrings[0].resize(k+1); // Append new last char
                                substrings[0][substrings[0].size()-1] = 'A' + q;
                                substrings.push_back(substrings[0]);
                                sort(substrings.begin(), substrings.end());
                            }
                        } else {
                            substrings.push_back(s.substr(j, k-j+1));
                            sort(substrings.begin(), substrings.end());
                        }
                    }
                }
                for (string &u: substrings) {
                    prefixes.insert(u);
                }
            }
        }
        int ans = 1; // To ensure empty string is included
        for (auto &p: prefixes) {
            ans = (1LL * ans * p.size()) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
