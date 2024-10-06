
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

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        long long W, G, L;
        cin >> W >> G >> L;
        vector<long long> E(W + L - G + 1, 0);
        
        for (int j = W + L - G; j > 0; --j)
            E[j] = (1 + E[j + min((int)((j - (int)G)), 1)] + E[max(G - j, min((int)j + L, W)) + 1]) % MOD;
        
        cout << "Case #" << i << ": " << E[1] << endl;
    }
}
