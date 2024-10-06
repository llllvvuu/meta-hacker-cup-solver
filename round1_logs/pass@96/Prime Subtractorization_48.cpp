
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

const int MAXN = 10000000;
vector<int> sieve(MAXN + 1, 1);
vector<bool> diff_sieve(MAXN + 1, 0); // sieve for differences

void sieve_prep() {
    sieve[1] = 0;
    for (int i = 2; i * i <= MAXN; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                sieve[j] = 0;
            }
        }
    }
    // marking differences
    for (int i = 2; i < MAXN; i++) {
        for (int j = i + 2; j <= MAXN - i && j <= i + 10; j++) {
            if (sieve[i] && sieve[j] && sieve[j - i]) {
                diff_sieve[j - i] = true;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    sieve_prep();
    while (T--) {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 2; i <= n; ++i) {
            if (sieve[i] && diff_sieve[i]) count++;
        }
        cout << "Case " << T + 1 << ": " << count << endl;
    }
    return 0;
}
