
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

const int MAX = 15000000;

bool primes[MAX+1];

void sieve() {
    primes[0] = primes[1] = false;
    for (long long i = 2; i <= MAX; i++) {
        for (long long j = i * i; j <= MAX; j += i) {
            primes[j] = false;
        }
    }
}

int prime_diff_count[MAX+1];

void compute_prime_diffs() {
    prime_diff_count[0] = 0;
    for (int i = 2; i <= MAX; ++i) {
        if (primes[i]) {
            int j = i - 1;
            while (j > 0 && !primes[j]) j--;
            prime_diff_count[i - j]++;
            break;  // Only need the smallest difference
        }
    }
    for (int i = 2; i < MAX+1; ++i) prime_diff_count[i] += prime_diff_count[i-1];
}

int main() {
    sieve();
    compute_prime_diffs();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << (primes[N] ? prime_diff_count[N] - prime_diff_count[N-1] : 0) << endl;
    }
    return 0;
}
