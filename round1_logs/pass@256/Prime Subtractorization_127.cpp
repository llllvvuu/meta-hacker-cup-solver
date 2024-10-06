
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

int solve(int N) {
    vector<bool> sieve(N + 1, true);
    sieve[0] = false, sieve[1] = false; // 0 and 1 are not primes
    for (int i = 2; i * i < N; i++) {
        if (sieve[i]) { // Only consider numbers that can be primes (marked true)
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = false; // Mark multiples of the prime numbers
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (sieve[i] && (N < 4 || sieve[i - 2])) {
            // If the number is prime and i-2 is also prime (or handle N^2)
            count++;
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

    return 0;
}
