
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
#include <cmath>
using namespace std;

const int MOD = 998244353;

typedef long long ll;
vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = A.size();
    vector<vector<ll>> C(n, vector<ll>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
    return C;
}

vector<vector<ll>> pow_matrix(vector<vector<ll>>& A, ll p) {
    int n = A.size();
    vector<vector<ll>> res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        p >>= 1;
        A = multiply(A, A);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": ";
        if (W < G + L) {
            if (G >= W) cout << W - G << endl;
            else cout << "0" << endl;
        } else {
            cout << -1 << endl; // Impossible case
        }
    }
}
