
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
#include <map>
#include <string>
using namespace std;

long long mod = 998244353;

long long countNodes(const string& w) {
    map<int, long long> contrib;
    contrib[0] = 1;
    long long res = 1;
    int pos = 0;
    for (char c : w) {
        if (c == '?') {
            map<int, long long> new_contrib;
            for (const auto& it : contrib) {
                new_contrib[it.first + 1] = (new_contrib[it.first + 1] + it.second * 26) % mod;
            }
            auto it = contrib.rbegin();
            while (it != contrib.rend()) {
                new_contrib[it->first + 1] = (new_contrib[it->first + 1] + it->second) % mod;
                ++it;
            }
            contrib = new_contrib;
        } else {
            res += contrib[0];
            res %= mod;
            for (int i = 1; i <= pos; i++) {
                contrib[i] += contrib[i - 1];
                contrib[i] %= mod;
            }
            ++pos;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        long long total_nodes = 0;
        for (int n = 1; n <= N; n++) {
            string w;
            cin >> w;
            total_nodes += countNodes(w);
            total_nodes %= mod;
        }
        cout << "Case #" << t << ": " << (total_nodes + mod - 1) % mod << "\n";
    }
    return 0;
}
