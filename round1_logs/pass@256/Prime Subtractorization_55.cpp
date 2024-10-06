
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
#include <array>
#include <vector>
#include <iostream>
using namespace std;

constexpr int MAX_N = 10000001;

bitset<MAX_N> primes;

// Generates all primes up to N using the Sieve of Eratosthenes
void sieve(const int N) {
    primes.set(); // Initialize all to true
    primes[0] = primes[1] = false; 
    for (int i = 2; i <= N; i++) {
        if (!primes[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            primes[j] = false;
        }
    }
}

int count_subtractorizations(const int N) {
    sieve(N);
    int count = 0;
    for (int p = 2; p <= N - 2; ++p) {
        if (!primes[p]) continue;
        for (int smaller = 2; smaller <= N; ++smaller) {
            if (primes[smaller] && (p + smaller) <= N && primes[smaller + p]) {
                count++;
                break; // Once one valid pair is found, no need to keep checking
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
        cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
    }
    return 0;
}
