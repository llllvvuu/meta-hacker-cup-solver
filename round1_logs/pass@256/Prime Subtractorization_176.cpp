
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

vector<long long> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<long long> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;
        
        // Generate primes up to n
        vector<long long> primes = sieve(n);
        set<long long> prime_set(primes.begin(), primes.end());
        
        int cnt = 0;
        for (long long p : primes) {
            for (long long q : primes) {
                if (p > q) continue; // Avoid duplicate checks
                if (p - q <= n && prime_set.count(p - q)) {
                    cnt++;
                }
            }
        }
        
        // Each counted difference is counted twice, once as p - q and once as q - p. 
        // Exclude 0 to avoid counting the same prime twice.
        cout << "Case #" << test_case << ": " << cnt / 2 << endl;
    }
    return 0;
}
