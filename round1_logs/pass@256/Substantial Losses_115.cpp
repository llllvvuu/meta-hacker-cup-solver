
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
using namespace std;

const int mod = 998244353;

long long exp(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long W, G, L;
        cin >> W >> G >> L;
        if (W - L < G) {
            cout << "Case #" << t << ": " << (W - G) % mod << endl;
        } else {
            cout << "Case #" << t << ": " << exp((W - G) * 2 % mod + 1, mod - 2) << endl;
        }
    }
    return 0;
}
