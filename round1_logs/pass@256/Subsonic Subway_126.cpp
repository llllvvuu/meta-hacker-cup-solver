
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
#include <vector>
#include <iostream>
using namespace std;

vector<double> v;
bool possible;

void solve(int N) {
    v.resize(N);
    possible = true;
    for (int i = 2; i <= N; ++i) {
        v[i] = max(1.0 / v[i - 1] * (i - 1), double(i) / v[i]);
        if (v[i - 1] * i > v[i] * (i - 1)) possible = false;
        v[i] = 1.0 / v[i];
    }
    if (!possible) v[N] = -1.0;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        v.resize(N + 1);
        for (int i = 1; i <= N; ++i) {
            double A, B;
            cin >> A >> B;
            if (i == 1 || (v[i - 1] > B || v[i] < A)) {
                possible = false;
            }
            v[i] = A;
            cin >> B;
            v[i] = max(v[i], B);
        }
        solve(N);
        cout << "Case #" << t << ": " << v[N] << '\n';
    }
    return 0;
}
