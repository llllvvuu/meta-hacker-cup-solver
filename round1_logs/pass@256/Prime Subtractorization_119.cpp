
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

const int MAX_N = 10000000;

vector<bool> is_prime(MAX_N + 1, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int count_n_subtractorizations(int n) {
    vector<bool> valid_primes(MAX_N + 1, false);
    // Mark all valid primes as true
    for (int prime : primes) {
        if (prime > n) break;
        valid_primes[prime] = true;
    }
    int ans = 0;
    for (int i = 0; i < primes.size() && primes[i] <= n; ++i) {
        // Ensuring prime[i] <= prime[j] always
        for (int j = i; primes[j] <= n; ++j) {
            int diff = primes[j] - primes[i];
            if (diff > 0 && diff <= n && valid_primes[diff]) {
                ans++;
                break; // Only need one pair per valid 'i'
            }
        }
    }
    return ans;
}

int main() {
    sieve();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << count_n_subtractorizations(n) << endl;
    }
    return 0;
}
