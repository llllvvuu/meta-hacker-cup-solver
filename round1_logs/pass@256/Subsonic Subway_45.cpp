
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
#include <bits/stdc++.h>
using namespace std;

void work() {
    int N;
    cin >> N;
    vector<double> LB(N), UB(N);

    for (int i = 0; i < N; ++i) {
        int A, B;
        cin >> A >> B;
        LB[i] = (double)i / B;
        UB[i] = (double)i / A;
    }

    double low = 0;
    double high = 1e9 + 5;
    for (double i = 0; i < N; ++i) {
        low = max(low, LB[i]);
        high = min(high, UB[i]);
    }

    if (high > low) {
        double ans = max(low, low);
        cout << ans << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        work();
        cout << "\n";
    }
}
