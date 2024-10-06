
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

const int MOD = 998244353;
int N;
vector<string> ws;

int dfs(int w, int used = 1) {
    if (w == N) return used;
    return (int64_t)dfs(w + 1, used) * (ws[w].size() - count(ws[w].begin(), ws[w].end(), '?') + 1) % MOD + dfs(w + 1, used * 26 % MOD);
}

int solve() {
    cin >> N;
    ws.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ws[i];
    }
    return (dfs(0) + MOD - 1) % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
