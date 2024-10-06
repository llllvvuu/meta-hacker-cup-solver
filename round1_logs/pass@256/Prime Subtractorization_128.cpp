
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
const int MAXP = 10000001;

bool prime[MAXP], prime_dif[MAXP];

int main() {
    memset(prime, true, sizeof(prime));
    int maxP = 2;
    for (long long i = 2; i < MAXP; i++) {
        if (prime[i]) {
            prime_dif[i - 2] = true;
            for (long long j = i * i; j < MAXP; j += i) {
                if (j - i >= 2) prime_dif[j - i] = false;
                prime[j] = false;
            }
            if (i > maxP) maxP = i;
        }
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int ans = 0;
        for (int i = 2, geq2 = 2; i <= min(N, maxP); i++) {
            if (prime[i])
                ans += prime_dif[max(geq2, i - N)];
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
