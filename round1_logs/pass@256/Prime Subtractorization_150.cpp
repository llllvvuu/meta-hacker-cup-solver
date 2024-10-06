
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
using std::cin;
using std::cout;

// k can be changed if precomputation limit needs to be increased
constexpr const size_t k = 10000007;
unsigned int is_prime[k];
size_t sieve_size = 10000000;

void compute_primes() {
    // Sieve of Eratosthenes to compute all primes up to 10,000,000
    for (size_t i = 0; i < k; ++i) is_prime[i] = 1;
    is_prime[0] = is_prime[1] = 0;
    for (size_t i = 2; i * i <= sieve_size; ++i) {
        if (is_prime[i] == 1) {
            for (size_t j = i * i; j <= sieve_size; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

size_t prime_subtractorizations(size_t n) {
    compute_primes();
    size_t count = 0;
    // This could be vector<vector<bool>>, but it's not necessary for the task
    bool dp[k];
    std::fill(dp, dp + k, false);
    for (size_t right = 2; right <= n; ++right) {
        if (!is_prime[right]) 
            continue;
        for (size_t left = 2; left < right; ++left)
            if (is_prime[left])
                dp[right - left] = true;
    }
    for (size_t i = 2; i <= n; ++i) {
        if (dp[i]) 
            ++count;
    }
    return count;
}

int main() {
    size_t t;
    cin >> t;
    for (size_t i = 0; i < t; ++i) {
        size_t n;
        cin >> n;
        cout << "Case #" << i + 1 << ": " << prime_subtractorizations(n) << "\n";
    }
    return 0;
}
