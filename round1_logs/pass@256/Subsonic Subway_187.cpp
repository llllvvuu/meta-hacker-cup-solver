
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
#include <algorithm>

using namespace std;

int slowest_speed_possible(int N, vector<int> a, vector<int> b) {
    long long T_start = (long long)a[0];
    long long T_end = max((long long)b[N - 1], (long long)N * 1000000);
    long long ans = -1;

    while (T_start <= T_end) {
        long long T_mid = (T_start + T_end) / 2;
        vector<int> c(N);
        bool can_reach = true;
        for (int i = 0; i < N; i++) {
            c[i] = a[i] + ((long long)a[i] + (long long)i * 1000000 > b[N - 1 - i] ? b[N - 1 - i] : (long long)a[i] + (long long)i * 1000000);
        }

        sort(c.begin(), c.end());
        c[0] = c[N - 1];

        for (int i = 0; i < N - 1; i++) {
            if (c[i] > c[i + 1] && c[i] == T_mid) can_reach = false;
        }

        if (can_reach) {
            T_start = T_mid + 1;
            ans = T_mid;
        } else {
            T_end = T_mid - 1;
        }
    }
    if (ans == 10000000) ans = -1;
    return (int)ans;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i] >> b[i];
        }
        cout << "Case #" << t << ": " << (double)slowest_speed_possible(N, a, b) / 1000000 << endl;
    }
    return 0;
}
