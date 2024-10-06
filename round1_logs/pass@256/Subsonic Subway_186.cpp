
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
#include <iostream>
#include <vector>
using namespace std;

const int BIG = (1 << 30) - 1;

double solve(int n) {
    vector<int> al(n), bl(n);
    double r = 0, l = 0, res = BIG;
    for (int i = 0; i < n; i++)
        cin >> al[i] >> bl[i];
    for (int i = n - 1; i >= 0; i--) {
        l = max(l, (double)((i + 1) * bl[i] - BIG * al[i]) / bl[i]);
        r = max(r, (double)((i + 1) * al[i]) / bl[i]);
        if (l > r) return -1;
        res = min(res, (double)(i + 1) / (l + (1e-9)));
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        printf("Case #%d: %.8f\n", t, solve(n));
    }
}
