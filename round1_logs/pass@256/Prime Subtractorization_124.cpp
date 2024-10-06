
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
#include <algorithm>
using namespace std;

const int MAX_N = 10000000 + 10; // Limit for the maximum value of N

bool is_prime[MAX_N]; // Array for prime sieve
vector<int> primes; // Vector to store prime numbers

void sieve() {
    fill(is_prime, is_prime + MAX_N, true);
    // special case 
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i < MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < MAX_N; j += i)
                is_prime[j] = false;
        }
    }
}

bool check_prime(int num) {
    if (num <= 1) return false;
    if (binary_search(primes.begin(), primes.end(), num)) return true;
    return false;
}

int main() {
    sieve(); // Generate prime numbers using sieve of Eratosthenes
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        if (N > 2) {
            // If N is greater than 2
            if (N % 2 == 0) {
                // If N is even, the only possible difference is 2 (even)
                cout << 1 << endl;
            } else {
                // If N is odd, count all unique primes p for which N-p is also a prime
                int count = 1; // 2 is always a substractionization for odd N
                for (int i = 2; i * 2 <= N; i++) {
                    if (is_prime[i] && is_prime[N - i])
                        count++;
                }
                cout << count << endl;
            }
        } else {
            // If N is 2 or less, no prime is a valid substractionization
            cout << 0 << endl;
        }
    }
    return 0;
}
