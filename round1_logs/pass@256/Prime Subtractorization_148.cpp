
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

// Function to mark the primes using Sieve
void sieve(bool *isPrime, int N) {
    fill(isPrime, isPrime + N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p)
                isPrime[i] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        vector<bool> isPrime(N + 1);
        sieve(isPrime, N);

        int count = 1;  // Always including '2'
        for (int i = 3; i <= N; i++) {
            if (isPrime[i] && i - 2 > 1 && isPrime[i - 2])
                count++;
        }
        cout << count << endl;
    }
    return 0;
}
