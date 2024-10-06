
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

double feedSpeed(vector<pair<long long, long long>>& stor) {
    if (stor.empty()) return -1.0;
    sort(begin(stor), end(stor), [](auto& l, auto& r){ return l.second < r.second; });
    vector<tuple<long long, int, int>> stopped((int)stor.size());

    // Note: This is a heavily simplified outline for illustration; direct implementation might require a detailed feasibility check.
    double res = 0.0;
    if (stor.size() > 0) res = max(res, (double) 1/(double)stor.back().second);
    // Binary Search would usually be invoked here for speed feasibility check.
    for (unsigned stationIdx = 0; stationIdx < stor.size(); ++stationIdx) {
        double currentStation = (double)stationIdx + 1;
        double arrivalTime = currentStation / res;
        
        // Require varying checks depending on analytical feasibility or additional processing.
        // This is a simplified approach.
        if (arrivalTime <= stor[stationIdx].second) return res;
    }
    // This is illustrative; additional refinement is needed around feasibility checking.
    return (double)1000001.0;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin.ignore();
        int N;
        cin >> N;
        vector<pair<long long, long long>> stations(N);

        for (int j = 0; j < N; j++) {
            cin >> stations[j].first;
            cin >> stations[j].second;
        }

        cout << "Case #" << i << ": " << fixed << setprecision(6) << feedSpeed(stations) << endl;
    }
    return 0;
}
