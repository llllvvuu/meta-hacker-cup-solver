
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

// Sieve of Eratosthenes to generate all primes up to N
vector<bool> generatePrimes(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

// Main function implementing Step 8 and taking input for multiple test cases
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        vector<bool> is_prime = generatePrimes(N);
        int count = 0;
        for (int p = 2; p <= N; ++p) {
            if (is_prime[p]) {
                for (int q = 2; q <= p; ++q) {
                    if (is_prime[q] && is_prime[p - q]) {
                        count++;
                        break;  // Found valid N-subtractorization
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
