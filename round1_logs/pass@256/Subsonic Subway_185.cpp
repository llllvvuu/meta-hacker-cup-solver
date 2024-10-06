
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
#include <vector>
using namespace std;

const int MAX_N = 1e6;

int N, get_delivery_time[MAX_N];

struct test_case {
    vector<int> A, B;
    
    void operator()() {
        cin >> N;
        A.assign(N, 0);
        B.assign(N, 0);
        for (int i = 0; i < N; ++i) {
            cin >> A[i] >> B[i];
            get_delivery_time[i] = A[i];
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        double ans = binary_search();
        printf("Case #%d: %.10f\n", ++case_idx, ans);
    }

    double binary_search() {
        const double eps = 1e-6 * 1e6;
        double L = 0, R = 1e6 + 1;
        int rounds = 0;
        while (rounds++ < 40) {
            double M = (L + R) / 2;
            if (check(M)) {
                R = M;
                continue;
            }
            L = M;
        }
        return (L + R) / 2;
    }
    
    static bool check(double speed) {
        double lowest = 1. / speed;
        for (int i = 0, j = 0; i < N; ++i) {
            double x = (i + 1) / speed;  // delivery time
            while (j < N && A[j] <= x) {
                lowest = min(lowest, 1. / (B[j] - i));
                ++j;
            }
        }
        return lowest <= speed;
    }
};

int main() {
    int T;
    cin >> T;
    vector<test_case> tests(T);
    for (auto &test : tests) {
        test();
    }
    cout << endl;
}
