
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

const int MOD = 998244353;

// Computes x^y under modulo
int power(int x, int y) {
    vector<int> powers = {1};
    int current = x;
    while (y > 0) {
        if (y % 2) {
            powers.push_back(current);
        }
        current = (1LL * current * current) % MOD;
        y /= 2;
    }
    return powers.back();
}

// Computes x^(-1) under modulo
int inv(int x) {
    return power(x, MOD-2);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int W, G, L;
        cin >> W >> G >> L;
        int diff = W - G;
        int result = (diff);
        if (diff > L) {
            int power_res = inv(power(2, diff));
            int factor = (1 + power_res) % MOD;
            int factor_multiple = (1LL * factor * inv(2)) % MOD;
            result = (1LL * result * factor_multiple) % MOD;
        }
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
