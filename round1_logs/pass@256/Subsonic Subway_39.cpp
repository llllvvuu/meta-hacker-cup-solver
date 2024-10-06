
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
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Interval {
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};

bool operator<(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Interval> intervals(N);
        for (int i = 0; i < N; ++i) {
            int A, B;
            cin >> A >> B;
            intervals[i] = Interval(A + i, B + i);
        }
        sort(intervals.begin(), intervals.end());

        int l = -1, h = intervals.size();
        double answer = 1e9;
        double current_end = 0;
        
        bool impossible = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i].start >= current_end + 1e-7) {
                double high_bound = intervals[i].end - intervals[i].start;
                current_end = intervals[i].end;
                if (high_bound == 0) {
                    impossible = true;
                    break;
                }
                answer = min(answer, double(intervals[i].start) / high_bound);
            } else if (intervals[i].end > current_end) {
                current_end = intervals[i].end;
            }
        }
        
        if (impossible) {
            cout << "Case #" << t << ": " << "-1" << endl;
        } else {
            cout << "Case #" << t << ": " << fixed << setprecision(6) << answer << endl;
        }
    }
    return 0;
}
