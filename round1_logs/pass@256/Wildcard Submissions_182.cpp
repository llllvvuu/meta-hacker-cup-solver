
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
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MOD = 998244353;

long dfs(vector<long>& bp, int rec, map<vector<long>, long>& mds, int d, long add) {
    long res = (long)((1LL * bp[d] + add) % MOD);
    if ((int)bp.size() > d + 1) {
        res = (res - dfs(bp, rec, mds, d + 1, res) + MOD) % MOD;
    }
    long now = 0;
    for (int i = 0, end = 26; i <= end; i++) {
        if (i == rec && rec != -1 || (i != 26 && !bp[d]++)) {
            continue;
        } else if (i != 26) {
            long tmp = 1;
            if (--bp[d] == 0 && (int)bp.size() > d + 1) {
                tmp = dfs(bp, (i == 26 ? -1 : i), mds, d + 1, 0);
            }
            if (!now) {
                now = tmp;
            } else {
                now += tmp;
            }
            now %= MOD;
            bp[d]++;
        }
    }
    mds[bp] = res;
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cout << "Case #" << cas << ": " ;
        int N;
        cin >> N;
        map<vector<long>, long> mds;
        vector<long> bp;
        bp.resize(101, 0);
        long res = 1;
        for (int i = 0, end = N; i < end; i++) {
            char tmp[105];
            cin >> tmp;
            int len = strlen(tmp);
            for (int j = 0; j < len && (int)bp.size() <= j; j++) {
                bp.resize(j + 2);
            }
            for (int j = len - 1; ~j; j--) {
                if (tmp[j] == '?') {
                    bp[j] = 25;
                } else {
                    bp[j] = tmp[j] - 'A';
                }
            }
            res = (res + dfs(bp, -1, mds, 0, 0)) % MOD;
        }
        cout << res << endl;
    }
}
