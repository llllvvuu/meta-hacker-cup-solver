
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
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000007;

vector<int> generatePrimes(int n) {
    vector<bool> is_prime(n + 1, true); 
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

int N;
int solve() {
    cin >> N;
    auto primes = generatePrimes(N);
    vector<int> prime_diffs; 
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i+1; j < primes.size(); j++) {
            int diff = primes[j] - primes[i];
            if (diff > N) break;
            if (binary_search(primes.begin(), primes.end(), diff)) {
                if (diff > 1 && prime_diffs.back() != diff) 
                    prime_diffs.push_back(diff);
            }
        }
    }
    return prime_diffs.size();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
