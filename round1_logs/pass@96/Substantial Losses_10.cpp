
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

const long long mod = 998244353;

long long expmod(long long x, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n % 2) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

long long inv(long long x) {
    return expmod(x, mod - 2, mod);
}

long long solve(long long w, long long g, long long L) {
    if (w == g) return 0;
    vector<long long> A, B = {1};
    long long factor = 2;
    for (long long i = 1; i <= g - w + L; i++) {
        A.push_back(factor);
        factor *= 2;
    }
    factor = 1;
    for (long long i = w - L; i <= g; i++) {
        B.push_back(factor);
        factor *= inv(2);
    }
    A.pop_back();
    A.pop_back();
    A.push_back(-1);
    B.pop_back();
    long long a = 0, b = 0;
    for (long long i = 0; i < A.size(); i++) {
        a = (a + A[i]) % mod;
        if (A[i] % 2 == 1) b = (b + B[i]) % mod;
    }
    return a * inv(b) % mod;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << endl;
    }
    return 0;
}
