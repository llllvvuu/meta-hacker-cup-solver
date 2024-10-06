
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

const int MAXN = 10000000;  // Adjust limit as per problem requirement

vector<int> primes_sieve(int n) {
    vector<bool> is_prime(n+1, true);
    vector<int> primes;
    for (int p = 2; p <= n; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (int i = p * 2; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

int count_subtractors(int N) {
    // Adjust n to N+2 as we consider adding +2 in generator
    int n = N + 2;
    vector<int> primes = primes_sieve(n);
    int count = 0;
    for (int &p : primes) {
        if(p > N) break; // exceeding N implies no more subtractorizations possible
        for(int i = 1, sz = primes.size(); i < sz; i += 1){
            if(primes[i] - p > N) break; // If j - p is greater than N, can't form a valid subtractorization.
            if(primes[i] - p == p) count++; // This means we found a valid subtractorization
        }
    }
    return count;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        cout << "Case #" << t << ": " << count_subtractors(N) << endl;
    }
    return 0;
}
