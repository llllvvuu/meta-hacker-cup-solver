
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
using namespace std;

const int P = 998244353, N = 28, mod = 10000;

struct vector_ {
    int size, data[N];
    vector_(int size = 0, int val = 0) : size(size) { fill(data, data + size, val); }
    vector_ operator+(const vector_ &b) const {
        vector_ c(size, 0);
        for (int i = 0; i < size; i++) c.data[i] = (data[i] + b.data[i]) % P;
        return c;
    }
    vector_ operator*(const vector_ &b) const {
        vector_ c(size, 0);
        for (int i = 0, j = N - size; i < size; i++, j++) {
            for (int k = 0; k < j; k++) c.data[i] = (c.data[i] + 1ll * data[i] * b[k]) % P;
        }
        return c;
    }
} dp[100];

int main() {
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, ans = 1;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            dp[0] = vector_(1, 1); dp[0].data[0] = 0;
            for (char c : s) {
                int pos = isalpha(c) ? int(c) - 65 : mod;
                ans = (ans + dp[i * 2 - 1].data[pos] * (i ? 1 : 26)) % P;
                dp[i * 2] = (dp[i * 2 - 1] * (i ? dp[i * 2 - 1] : vector_(26, 1))) + dp[i * 2];
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
}
