
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

vector<int> dx; // Required speeds for minimum
vector<int> dy; // Required speeds for maximum

double minSpeed;

void getMin() {
    int cur_dx = 0; // Index in dx array.
    int cur_dy = 0; // Index in dy array.
    double cur_b = -1; // Current min we can get.
    while (cur_dx != dx.size() || cur_dy != dy.size()) {
        if (cur_b == -1 || dy[cur_dy] < dx[cur_dx]) {
            // We can achieve dy[cur_dy], and we'll update our answer accordingly.
            cur_b = double(dy[cur_dy]);
            cur_dy++;
        } else {
            cur_b = max(cur_b, double(dx[cur_dx]));
            cur_dx++;
        }
        minSpeed = min(minSpeed, cur_b);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        dx.clear();
        dy.clear();
        
        for (int i = 1; i <= N; i++) {
            double a, b;
            cin >> a >> b;
            dx.push_back(i / b); // Speeds for minimum distance
            dy.push_back((i - 1) / a); // Speeds for maximum distance required
        }

        // Sort them to find intervals.
        sort(dx.begin(), dx.end());
        sort(dy.begin(), dy.end());

        // Set minimum speed to infinity
        minSpeed = INF;
        getMin();
        
        if (minSpeed == INF) {
            cout << "Case #" << t << ": " << -1 << endl;
        } else {
            cout << "Case #" << t << ": " << setprecision(9) << minSpeed << endl;
        }
    }
    return 0;
}
