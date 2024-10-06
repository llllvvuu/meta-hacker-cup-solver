
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
#include <unordered_map>
#include <iostream>
using namespace std;

const int BASE = 29;
const int MOD = 998244353;

int countNodes(const std::string& s, int mask) {
    int h = 0;
    unordered_map<int, int> m;
    m[0] = 1; // root

    for(auto ch : s) {
        if(ch == '?') {
            for(int c = 0; c < 26; c++) {
                h = (h * BASE + c + 1) % MOD;
                if(!m.count(h)) m[h] = ++mask;
            }
            h = h / BASE % MOD;
        } else h = (h * BASE + ch - 'A' + 1) % MOD;
        if(!m.count(h)) m[h] = ++mask;
    }
    return mask;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int mask = 1, ans = 0;

        for(int i = 0; i < N; i++) {
            string S_i;
            cin >> S_i;
            ans = (ans + countNodes(S_i, mask)) % MOD;
            mask = ans + 1;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
