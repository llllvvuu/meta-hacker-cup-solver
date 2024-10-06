
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

int sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

int primeDifferences(int n) {
    auto isPrime = sieve(n);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    int count = 0;
    if (isPrime[2]) count++;
    
    int p_idx = 1;
    for (int i = 1; primes[i] <= n / 2; i++) {
        while (p_idx < primes.size() && primes[p_idx] <= n) {
            if (primes[p_idx] - primes[i] <= n) {
                count++;
            }
            p_idx++;
        }
    }

    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << primeDifferences(n) << "\n";
    }
    return 0;
}
