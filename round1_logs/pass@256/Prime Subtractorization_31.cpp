
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

// Generates all primes up till maxN using the Sieve of Eratosthenes.
vector<int> sieve(int maxN) {
    vector<int> isPrime(maxN + 1, 1);
    vector<int> primes;
    for (int p = 2; p * p <= maxN; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= maxN; multiple += p) {
                isPrime[multiple] = 0;
            }
        }
    }
    for (int i = 2; i <= maxN; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        if (N <= 1) {
            cout << 0 << endl;
            continue;
        }
        if (N == 2) {
            cout << 1 << endl;
            continue;
        }

        vector<int> primes = sieve(N);

        int answer = 0;
        int size = primes.size();
        for (int i = 0; i < size && primes[i] < N; i++) {
            int prime = primes[i];
            if (i < size - 1 && primes[i+1] > N) {
                break;
            }
            if (prime < N && 2 * prime <= N) {
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
