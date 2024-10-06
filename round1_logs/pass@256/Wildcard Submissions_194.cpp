
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
const int MOD = 998244353;

vector<long long> multiply(const vector<long long>& v, const vector<long long>& w) {
    int n = v.size();
    vector<long long> r(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < min(n - i, (int)w.size()); j++) {
            r[i + j] = (r[i + j] + v[i] * w[j]) % MOD;
        }
    }
    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    vector<long long> counts(26, 1);  // Base case: Any single letter as base count
    
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        char sv[101];
        for (int i = 0; i < N; i++) {
            cin.getline(sv, 101);  // Reading the string
            counts.assign(26, 1);  // Reset counts
            long long content = 1;
            for (char c : sv) {
                if (c == '?') {
                    long long new_content = 0;
                    for (int j = 0; j < 26; j++) {
                        new_content = (new_content + counts[j]) % MOD;
                    }
                    content = content * new_content % MOD;
                } else {
                    content = contents[c - 'A'];
                }
            }
            for (int j = 0; j < 26; j++) {
                counts[j] = (contents[j] + content) % MOD;
            }
        }
        cout << "Case #" << t << ": " << accumulate(counts.begin(), counts.end(), 0LL) % MOD << '\n';
    }
    return 0;
}
