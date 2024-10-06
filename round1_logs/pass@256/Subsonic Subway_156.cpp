
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
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;

const long double INF = 1e18;  // A large number.
const long double EPS = 1e-8;  // A small number to handle precision issues.

struct Segment {
    long double l, r;
    bool operator<(const Segment &other)const {
        if(l == other.l) return r < other.r;
        return l < other.l;
    }
};

long double find_speed(const vector<Segment>& segments) {
    int n = segments.size();
    long double low = 0, high = INF;
    long double answer = -1.0;
    while(high - low > EPS) {
        long double mid = (low + high) / 2;
        vector<long double> times(n);
        vector<long double> overtakes;
        for(int i = 0; i < n; i++) {
            times[i] = (segments[i].l + segments[i].r) / 2.0;
            overtakes.push_back(segments[i].l - (mid * times[i]));
            overtakes.push_back(segments[i].r - (mid * times[i]));
        }
        sort(overtakes.begin(), overtakes.end());
        int missed = 0, prev_bin = INT_MIN;
        for(auto cur_overtake: overtakes) {
            missed += cur_overtake > prev_bin;
            missed -= cur_overtake > times[missed - 1];
            prev_bin = max(prev_bin, times[missed - 1]);
        }
        if(missed <= 1)
            high = mid, answer = mid;
        else
            low = mid;
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Segment> segments(N);
        for(int i = 0; i < N; i++) cin >> segments[i].l >> segments[i].r;
        cout << "Case #" << t << ": " << fixed << setprecision(12) << find_speed(segments) << "\n";
    }
    return 0;
}
