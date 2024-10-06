
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
#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
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
        
        vector<int> primes = sieve(N);
        unordered_set<int> prime_differences;

        for (int i = 0; i < primes.size(); ++i) {
            for (int j = 0; j < primes.size(); ++j) {
                int diff = primes[i] - primes[j];
                if (diff > 0 && diff <= N && find(primes.begin(), primes.end(), diff) != primes.end()) {
                    prime_differences.insert(diff);
                }
            }
        }
        
        cout << prime_differences.size() << endl;
    }
    return 0;
}
