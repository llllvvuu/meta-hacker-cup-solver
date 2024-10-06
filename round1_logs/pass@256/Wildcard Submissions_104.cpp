
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

const int MOD = 998244353;
const int N = (1 << 26);

vector<int> cnt[N];
int T, Ncases;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> Ncases;
        for (int i = 0; i < N; i++) cnt[i].resize(26, 1); // Initial value of 1
        int ans = 0;                       

        for (auto _ = 0; _ < Ncases; _++) {
            string s;
            cin >> s;
            int mask = 0;
            
            for (auto c : s) {
                int id = 25;
                if (c == '?') {
                    for (id = 0; id < 26; id++) {
                        if (__builtin_popcount(mask | (1 << id)) == (int)__builtin_popcount(mask) + 1) { // checks if adding a new char increases mask count
                            ans = (ans + cnt[mask][id]) % MOD;
                            cid = id;
                            break;
                        }
                    }
                } else {
                    ans = (ans + cnt[mask][id]) % MOD;
                }
                cnt[mask |= (1 << id)][c - 'A'] = (cnt[mask |= (1 << id)][c - 'A'] + cnt[mask][id]) % MOD;
            }          
        }
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
