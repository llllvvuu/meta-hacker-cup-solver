
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
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000006;

int T;
bool is_prime[MAXN];
vector<int> primes;

void sieve(int up_to) {
    memset(is_prime, true, sizeof(bool) * (up_to + 1));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= up_to; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= up_to; j += i) {
                is_prime[j] = false;
            }
        }
    }
    // Collect primes
    for (int i = 2; i <= up_to; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

// Get the number of N-subtractorizations
int get_count(int N) {
    int count = 0;
    // Try all pairs of primes (p, q) such that 2 <= q < p
    for (int i = 0; i < primes.size() && primes[i] <= N; i++) {
        for (int j = 0; j < i; j++) {
            int diff = primes[i] - primes[j];
            if (primes[j] <= N && is_prime[diff]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        sieve(N);
        cout << "Case #" << t << ": " << get_count(N) << endl;
    }
    return 0;
}
