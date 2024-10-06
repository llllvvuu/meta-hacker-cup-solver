
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
#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000000;

bitset<MAXN + 1> sieve, res;

void markNotPrime (int n) {
    for (int i = n * 2; i <= MAXN; i += n)
        sieve[i] = false;
}

void precompute (int n) {
    sieve.reset();
    sieve.set();
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (sieve[i])
            markNotPrime (i);
}

// This function checks if a range difference is prime and adds it to the result set.
void checkDifference(int p1, int p2, int& count) {
    int diff = p1 - p2;
    if (diff >= 2 && sieve[diff] && !res[diff]) {
        res[diff] = true;
        count++;
    }
}

// Input: N
// Output: The number of $N$-subtractorizations
int solve(int N) {
    precompute(N);
    int primeCount = 0;
    int count = 0;
    
    // Generate primes
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            primeCount++;
            // Check pairs (p1, i) for differences that are prime
            for (int j = i; j >= 2; --j) {
                if (sieve[j]) {
                    checkDifference(i, j, count);
                }
            }
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
}
