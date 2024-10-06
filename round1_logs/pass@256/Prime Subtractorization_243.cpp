
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
#include <unordered_set>
using namespace std;

bool segmented_sieve(long long N, vector<bool>& is_prime) {
    long long limit = sqrt(N) + 1;
    vector<bool> primes(limit + 1, true);
    vector<long long> primes_list;
    for (long long p = 2; p <= limit; p++) {
        if (primes[p]) {
            primes_list.push_back(p);
            for (long long i = p * p; i <= limit; i += p) {
                primes[i] = false;
            }
        }
    }
    for (long long p : primes_list) {
        long long first_multiple = (N + p - 1) / p * p;
        if (first_multiple <= N) is_prime[first_multiple - N] = false;
        for (long long i = p * p; i <= N; i += p) {
            is_prime[i - N] = false;
        }
    }
    is_prime[0] = is_prime[1] = false;  // 0 and 1 are not prime
    return true;
}

int count_subtractorizations(long long N) {
    if (N < 2) return 0;  // No prime numbers are subtractorizations for N < 2
    vector<bool> is_prime(N, true);
    segmented_sieve(N, is_prime);
    unordered_set<long long> prime_diffs;
    for (long long p1 = 2; p1 <= N; p1++) {
        if (!is_prime[p1]) continue;
        for (long long p2 = p1 + 1; p2 <= N; p2++) {
            if (!is_prime[p2]) continue;
            long long diff = p2 - p1;
            if (diff > N) break;
            prime_diffs.insert(diff);
        }
    }
    return prime_diffs.size();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N;
        cin >> N;
        cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
    }
    return 0;
}
