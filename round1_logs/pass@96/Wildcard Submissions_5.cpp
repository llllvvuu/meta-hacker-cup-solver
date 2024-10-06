
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
#include <cstdint>
#include <iostream>
#include <array>
#include <climits>
#include <vector>
#include <string>

using namespace std;

const int64_t MOD = 998'244'353;
 
int solve(vector<string> patterns) {
    array<array<int64_t, 26>, 100> cnt = {};
    cnt[0][25] = 1;  // base case
    
    for (int i = patterns.size() - 1; i >= 0; i--) {
        const auto& p = patterns[i];
        auto c = cnt;
        for (int j = 0; j < p.length(); j++) {
            int64_t mask = 0;
            if (p[j] == '?') {
                for (int c = 0; c < 26; c++) {
                    mask ^= 2 * (1LL << c) * cnt[i][c];
                }
            }
            cnt[i][p[j] - 'A'] = mask;
        }
    }
 
    int64_t result = 1;
    for (int i = 0; i < patterns.size(); i++) {
        for (int j = 0; j < 25; j++) {
            int64_t prod = result * c[i][j] % MOD;
            if (prod > INT_MAX) {
                prod = prod % MOD;
            }
            result = result + prod;
            if (result >= MOD) {
                result -= MOD;
            }
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        cout << "Case #" << t << ": " << solve(S) << endl;
    }
    return 0;
}
