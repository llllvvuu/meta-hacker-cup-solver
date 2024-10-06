
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

const int LIMIT = 10000005;

vector<bool> prime(LIMIT, true);
vector<int> primes;

void mark_mult(int p, bool* arr) {
  for (int i = p * p; i < LIMIT; i += p) arr[i] = false;
}

// Generates all primes up to LIMIT using sieve of Eratosthenes
void generate_primes() {
    for (int i = 2; i < LIMIT && prime[i]; ++i) {
        if (prime[i]) primes.push_back(i);
        mark_mult(i, prime.data());
    }
}

// Generates all valid N-subtractorizations given a limit N
int subtractorizations(int N) {
    vector<bool> is_prime = prime;
    generate_primes();

    int count = 0;
    for (int p : primes) {
        if (p > N) break;
        int q = N - p; //Potential subtractorization
        if (q >= p && is_prime[q]) {
            count++;
            if (q - p < LIMIT) is_prime[q - p] = false; // avoid double counting
        }
    }
    return count ? count : 1; // At least 2, as 2 can always be formed (N - (N-2) = 2)
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    generate_primes(); // we only need to generate primes once
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << subtractorizations(N) << endl;
    }
    return 0;
}
