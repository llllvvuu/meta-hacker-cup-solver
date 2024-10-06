
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

int multiply(int a, int b) {
    return (1LL * a * b) % MOD;
}

int solve(int n, vector<string> &wildcards) {
    vector<int> counts(101, 1); // initially each prefix length has 1 (root)
    for (int i = 0; i < n; i++) {
        string &w = wildcards[i];
        for (int j = w.size() - 1; j >= 0; j--) {
            if (w[j] == '?') {
                counts[j + 1] = multiply(counts[j + 1], 27);
            } else {
                counts[j + 1] = counts[j];
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < 101; i++) {
        answer = (answer + counts[i]) % MOD;
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int n;
        cin >> n;
        vector<string> wildcards(n);
        for (int i = 0; i < n; i++) {
            cin >> wildcards[i];
        }
        cout << solve(n, wildcards) << endl;
    }
    return 0;
}
