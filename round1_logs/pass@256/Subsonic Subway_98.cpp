
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
#include <iostream>
using namespace std;

const double INF = 1e9;

bool check(double speed, int A[], int B[], int N) {
    double beg, end;
    beg = (double)1 / B[0];
    end = (double)1 / A[0];
    if (speed < beg || speed > end) {
        return false;
    }
    for (int i = 1; i < N; i++) {
        beg = max(beg, (double)1 / B[i]);
        end = min(end, (double)1 / A[i]);
        if (beg > end) {
            return false;
        }
    }
    beg = (double)1 / speed;
    throw (double)1 / beg;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;

        while (cin.peek() == '\n') cin.ignore(); // skip newline separators
        int A[N], B[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }
        if (N == 1) {
            cout << fixed << setprecision(7) << 1.0 / B[0] << endl;
        } else {
            double l = 1e-10, r = 1e9;
            for (int i = 0; i < 100; i++) { // Iterative refinement
                double m = (l + r) / 2.0;
                if (check(m, A, B, N)) {
                    r = m;
                } else {
                    l = m;
                }
            }
            cout << fixed << setprecision(7) << (check(l, A, B, N) ? l : -1) << endl;
        }
    }
    return 0;
}
