
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
#include <vector>
#include <iostream>
using namespace std;

const int MAX_N = 10000000 + 1;

vector<int> sieve() {
    vector<bool> is_prime(MAX_N, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX_N; ++i) {
        if (!is_prime[i]) continue;
        primes.push_back(i);
        for (long long j = (long long)i * i; j < MAX_N; j += i) {
            is_prime[j] = false;
        }
    }
    return primes;
}

int solve(int N) {
    vector<int> primes = sieve();
    int res = 0;
    vector<int> subtractorizations;
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = 0; j < primes.size(); ++j) {
            if (primes[i] - primes[j] <= N && !is_prime[primes[i] - primes[j]]) continue;
            if (primes[i] - primes[j] <= N && subtractorizations.find(primes[i] - primes[j]) == subtractorizations.end()) {
                subtractorizations.push_back(primes[i] - primes[j]);
            }
        }
    }
    return subtractorizations.size();
}

int main() {
    vector<int> primes = sieve();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
