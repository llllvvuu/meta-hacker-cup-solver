
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
vector<int> primes;

void sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}

int num_subtractorizations(int n) {
    int ans = 0;                        // Count of distinct prime differences
    sieve(2 * n);                       // Precompute primes up to 2N 
    vector<int> diff_primes;            // Stores all differences that are prime
    for (auto p: primes) {              // Iterate over all primes up to N
        for (auto t: primes) {          // Iterate over all primes t < N
            if (p >= t && p - t < n + 1) { 
                if (binary_search(primes.begin(), primes.end(), p - t)) {  // Check if the difference is prime 
                    diff_primes.push_back(p - t);  // If so, store the difference 
                }
            }
        }
    }
    // Use a set to ensure all differences are distinct and counted once
    sort(diff_primes.begin(), diff_primes.end());
    auto ip = unique(diff_primes.begin(), diff_primes.end());
    vector<int> freq(ip - diff_primes.begin());  // Frequency array
    for (int i = 0; i < ip - diff_primes.begin(); i++) freq[i] = 0;
    for (int i = 0; i < diff_primes.size(); i++) freq[i-(int)(diff_primes.begin())]++;
    return (int)freq.size();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << num_subtractorizations(N) << endl;
    }
    return 0;
}
