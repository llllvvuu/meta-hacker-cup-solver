
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
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
typedef long double ld;

ld ask(ld speed) {
    vector<ld> l;
    vector<ld> r;
    for (int i = 0; i < n; ++i) {
        l.push_back(ends[i][0] / (i + 1));
        r.push_back(ends[i][1] / (i + 1));
    }
    sort(begin(l), end(l));
    sort(begin(r), end(r));

    if (r[0] > l[n - 1]) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        int n;
        cin >> n;
        vector<pair<int, int>> ends(n);
        for (int i = 0; i < n; ++i) {
            cin >> ends[i].first >> ends[i].second;
        }
        ld left = 1e-9;
        ld right = 1e9;
        ld zero = 1.0 / (1e9 + 1);
        // Binary search
        while (right - left > zero) {
            ld mid = (left + right) / 2;
            if (ask(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << "Case #" << tt << ": ";
        if (right > 1e8) {
            cout << "-1";
        } else {
            cout << fixed << setprecision(15) << 1. / right;
        }
        cout << "\n";
    }
}
