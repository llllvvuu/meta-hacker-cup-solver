
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
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    long long l, r;
    Interval(long long l, long long r) : l(l), r(r) {}
    bool operator<(const Interval& other) const {
        return l != other.l ? l < other.l : r < other.r;
    }
};

const int maxN = 1000000;
Interval I[maxn];

int main() {
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<Interval> intervalls;
        for (int i = 0; i < N; ++i) {
            long long A, B;
            cin >> A >> B;
            if (i == N - 1 && A == 0) {
                cout << "Case #" << t << ": " << "-1\n";
                continue;
            } 
            intervalls.push_back(Interval(1 + i * 10000000L / B, i * 10000000L / A + maxN));
        }
        sort(intervalls.begin(), intervalls.end());
        if (lower_bound(intervalls.begin(), intervalls.end(), Interval(0, maxN))->l) {
            cout << "Case #" << t << ": " << "-1\n";
            continue;
        }
        long long minV = maxN * 10000L, maxV = 0, upper = maxN + maxN; // maxV = -1
        while (minV - maxV > 1) {
            long long mid = (minV + maxV) / 2;
            long long sumL = 0, sumR = 0;
            for (int i = 0, j = intervalls.size() - 1; (i < intervalls.size() && j > -1);) {
                bool borr = upper - intervalls[i].l > intervalls.back().r - intervalls[j].r;
                sumR += borr ? intervalls[j--].r : maxN;
                sumL += borr ? maxN : intervalls[i++].l;
            }
            if (sumL + upper > sumR)
                minV = mid;
            else 
                maxV = mid;
        }
        cout << fixed << setprecision(6) << "Case #" << t << ": " << (double) maxV / 10000 << '\n';
    }
}
