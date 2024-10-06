
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
using ll = long long;

const double eps = 1e-9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    for (ll t = 1; t <= T; t++) {
        ll N;
        cin >> N;
        vector<pair<ll, ll>> stations(N); 
        for (ll i = 0; i < N; i++) 
            cin >> stations[i].second >> stations[i].first;

        sort(begin(stations), end(stations));  // Sort based on deadlines (arrival times)
        
        double ans = -1;
        double lo = 0, hi = 1e9 + 10;   // Initialize bounds for binary search
       
        while(lo < hi - 1e-6){
            double mid = (lo + hi) / 2;
            bool feasible = true;
            for (ll i = 0, t = 0; i < N && feasible; i++) {
                t = max(t - mid / (2 * (i + 1) - 1), stations[i].second);
                if (t > stations[i].first) 
                    feasible = false; 
            }
            if (feasible) 
                ans = mid, lo = mid + eps;
            else 
                hi = mid - eps;
        }
        cout << "Case #" << t << ": " << fixed << setprecision(8) << ans << '\n';
    }
}
