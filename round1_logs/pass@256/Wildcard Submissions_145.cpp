
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

long long mod = 998244353;

void add(long long &a, long long b) {
    a = (a + b) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long n;
        cin >> n;
        vector<long long> distinctStatus;
        for (long long i = 1; i <= n; i++) {
            string s;
            cin >> s;
            vector<long long> ends(105, 0);
            long long all = 1, prefix = 1;
            for (long long j = 0; j < s.size(); j++) {
                all *= (s[j] == '?' ? 26 : 1);
                if (s[j] != '?') add(prefix, all);
            }
            add(distinctStatus.back(), prefix);
            for (long long j = s.size() - 1; j >= 0; j--) {
                if (s[j] != '?') continue;
                long long curAll = all;
                long long curPrefix = prefix;
                all *= 26;
                add(prefix, all - curAll);
                add(distinctStatus.back(), prefix - distinctStatus.back());
                distinctStatus.push_back(prefix);
            }
        }
        cout << "Case #" << t << ": " << distinctStatus.back() << endl;
    }
    return 0;
}
