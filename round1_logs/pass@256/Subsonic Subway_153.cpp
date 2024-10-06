
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
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000000;
const int MAXT = 1000000;
int n;
int x[MAXN];
int jn = 1;
int A[MAXT];
int B[MAXT];
bool mark[MAXT];
float A2[MAXT];
float B2[MAXT];
float T2[MAXT];
float unit = 100000000;

bool check(float d) {
    double idx = 0;
    for (int i = 1; i <= n; i++) {
        double dt = (double)d / i;
        double r;
        while (idx < MAXT && A2[idx] <= B2[i]) idx++;
        idx--;
        if (T2[idx] + dt < A2[i]) return false;
        r = T2[idx] + dt;
        while (idx > 0 && (r > B2[idx] || B2[i] > A2[idx])) idx--;
        T2[idx] = r;
    }
    return true;
}

void solve() {
    for (int i = 0; i < MAXT; i++) {
        A[i] = MAXT;
        B[i] = 0;
        A2[i] = i * unit;
        B2[i] = (i + 1) * unit;
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
        A2[i] = A[i] * unit;
        B2[i] = (A[i] + 1) * unit;
        T2[i] = B[i] * unit;
    }

    double lo = 0, hi = n * MAXT / unit;
    for (; lo <= hi;) {
        double mi = (lo + hi) / 2;
        if (check(mi))
            hi = mi - 0.00000001;
        else
            lo = mi + 0.00000001;
    }
    float ans = hi;
    if (ans > MAXT)
        cout << -1 << endl;
    else
        cout << ans / MAXT << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
