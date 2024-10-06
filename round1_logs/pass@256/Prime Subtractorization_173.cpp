
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
#include <map>
using namespace std;

map<int, int> validCache;

vector<int> sieve(int n) {
    vector<int> primes = {2};
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            primes.push_back(p);
            for (int i = p * p; i <= n; i += p) isPrime[i] = false;
        }
    }
    return primes;
}

int solve(int N) {
    vector<int> primes = sieve(N);
    for (int p: primes) validCache[p] = 0;

    for (int i = 0; i < (int)primes.size(); i++) {
        int p1 = primes[i];
        validCache[p1]++;
        for (int j = i + 1; j < (int)primes.size() && primes[j] - p1 <= N; j++) {
            int diff = primes[j] - p1;
            validCache[diff]++;
        }
    }

    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (validCache[i] >= 2) cnt++;
    }

    return cnt;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
