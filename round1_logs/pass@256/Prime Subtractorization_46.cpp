
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

// Function to generate all prime numbers up to n using the Sieve of Eratosthenes
vector<int> primes_up_to(const int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int solve(int n) {
    vector<int> primes = primes_up_to(n);
    vector<int> prime_diff_count(n + 1, 0);
    
    // Calculate prime differences and their counts
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i; j < primes.size(); ++j) {
            int diff = primes[j] - primes[i];
            if (diff <= n) {
                prime_diff_count[diff]++;
            } else {
                break;
            }
        }
    }
    
    // Count prime differences that are primes themselves
    int count = 0;
    for (int i = 0; i <= n; ++i) {
        if (prime_diff_count[i] > 0 && is_prime[i]) {
            count++;
        }
    }
    return count;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
