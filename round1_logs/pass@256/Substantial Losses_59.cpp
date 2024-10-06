
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int mod = 998244353;

struct trip {
    long long w, steps, weight;
    bool operator < (const trip &t) const {
        return make_tuple(weight, steps) < make_tuple(t.weight, t.steps);
    }
};

typedef tree<trip, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(long long w, long long g, long long l) {
    if (w <= g + l) {
        cout << (w - g) << "\n";
        return;
    }

    if (w <= g + l + 1) {
        cout << 1 << "\n";
        return;
    }

    ordered_set s;
    s.insert({w, 0, w});
    s.insert({w - 1, 1, w});

    while (g + l + 1 != s.find_by_order(0)->weight) {
        if (w - l - 2 >= g) {
            auto it = s.find_by_order(0);
            s.erase(it);
        }
        s.insert({w, it->steps + 1, it->weight - 2});
        s.insert({w - 1, it->steps + 1, it->weight - 1});
        it = s.find_by_order(0);
    }

    if (w > g + l + 1) {
        s.erase(s.find_by_order(1));
    }

    if (w + 1 < g + l + 1) {
        s.insert({w + 1, 0, w + 1});
    }

    auto it = s.find_by_order(0);
    long long p = it->steps, q = mod - mod / (s.find_by_order(1)->steps - it->steps);
    cout << (((p % mod) * (q % mod)) % mod);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        long long w, g, l;
        cin >> w >> g >> l;
        solve(w, g, l);
        cout << "\n";
    }
    return 0;
}
