
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
const int MOD = 998244353;

long long mod_exp(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long solve_case(const vector<string>& strings) {
    const int M = strings.size(), N = strings[0].size();
    long long count = 1;
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < M; j++) {
            if (strings[j][i] != '?')
                found = true;
        }
        if (found)
            count = (count * 26) % MOD;
        else
            count = (2 * count - mod_exp(26, i + 1)) % MOD;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        vector<string> strings(N);
        for (int j = 0; j < N; j++) {
            cin >> strings[j];
        }
        cout << "Case #" << i << ": " << solve_case(strings) << endl;
    }
    return 0;
}
