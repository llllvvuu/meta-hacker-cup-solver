
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
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

bitset<128> seen[101]; //track seen prefixes up to 100 char length

void dfs(string &pattern, int level = 0) {
    if(level == pattern.size()) return;
    int L = pattern[level] == '?' ? 26 : 1; //1 if real letter, 26 if '?';
    for(int i = 0; i < L; ++i) {
        if(pattern[level] == '?' || pattern[level] == 'A' + i) {
            seen[level][pattern[level] == '?' ? '.': (char)pattern[level]] = 1;
            dfs(pattern, level+1);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> patterns(N);

        for(auto &x : patterns) cin >> x;

        for(auto &pattern: patterns) {
            dfs(pattern);
        }
        long long ans = 1;
        for(int i = 0; i <= 100; i++) ans = (ans * seen[i].count()) % mod; //choose new with repetition

        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                seen[i-1] &= seen[j]; //carry to handle transitions between lengths
            }
        }

        ans = (ans * 1000000000 + mod - 1) % mod;

        cout << "Case #" << t << ": " << ans << "\n";

    	for(int i = 0; i < 101; i++) seen[i].reset(); //reset for next case
    }
    return 0;
}
