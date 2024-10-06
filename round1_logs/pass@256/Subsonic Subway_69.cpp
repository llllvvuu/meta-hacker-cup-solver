
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

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        double sMax = 0, sMin = INT_MAX;
        for (int i = 1; i <= N; i++) {
            long long a, b;
            cin >> a >> b;
            sMax = max(sMax, (double(i) / (double)a));
            sMin = min(sMin, (double(i) / (double)b));
        }
        cout << "Case #" << t << ": ";
        if (sMax > sMin) cout << "-1\n" ;
        else cout << setprecision(7) << fixed << sMax << "\n";
    }
    return 0;
}
