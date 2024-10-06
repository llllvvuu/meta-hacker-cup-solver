
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

// Sieve to find all primes up to N
vector<bool> sieve(int N) {
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p*p <= N; p++) {
        if (isPrime[p]) {
            for (int i = p*p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }
    return isPrime;
}

int solve(int N) {
    vector<bool> primes = sieve(N);
    bitset<10000001> results;
    for (int p = 2; p < N + 1; p++) {
        if (primes[p]) {
            for (int q = 2; q <= min(p, N+1-p); q++) {
                int r = p - q;
                if (r >= 2 and primes[r]) results[r] = true;
            }
        }
    }
    return results.count();
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << "\n";
    }
    return 0;
}
