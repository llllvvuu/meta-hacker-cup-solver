
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

struct Station {
    long long a, b, i;
    Station(long long a_, long long b_, long long i_) : a(a_), b(b_), i(i_) {}

    bool operator<(const Station &s) const {
        return a != s.a ? a < s.a : b < s.b;
    }
    // secondary comparator for b, in case of equality of delivering times
};

const double eps = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<Station> *stations = new vector<Station>[T];
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        for (int j = 0; j < N; j++) {
            long long a, b;
            cin >> a >> b;
            stations[i].push_back(Station(a, b, j));
        }
        sort(stations[i].begin(), stations[i].end());
    }
    for (int i = 0; i < T; i++) {
        long long N = stations[i].size();
        double left = 0, right = 1e6 + 99;
        while(right - left > eps) {
            double mid = (left + right) / 2;
            double total_time = 0;
            int curr_station = 0;
            for (int j = 1; j < N; j++) {
                total_time += stations[i][j].i / mid;
                while(curr_station + 1 < N && total_time > stations[i][curr_station + 1].b) {
                    curr_station++;
                }
                if (curr_station + 1 >= N || stations[i][curr_station].a > total_time) {
                    left = mid;
                    break;
                }
            }
            if (curr_station + 1 == N) {
                right = mid;
            }
        }
        cout << "Case #" << i + 1 << ": " << setprecision(10) << (left < 1e3 ? left : -1) << endl;
    }
}
