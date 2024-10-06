
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
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) 
                is_prime[i] = false;
        }
    }

    vector<int> primes;
    for (int i = 0; i <= n; i++) {
        if (is_prime[i]) 
            primes.push_back(i);
    }
    return primes;
}

int solve(int N) {
    vector<int> primes = sieve(N);
    vector<int> lower(primes.size()); // primes <= N/2
    vector<int> upper(primes.size()); // primes > N/2

    for (int i = 0, j = 0; i < primes.size(); i++) {
        if (primes[i] <= N / 2) {
            lower[j++] = primes[i];
        } else {
            upper[i - j] = primes[i];
        }
    }

    unordered_set<int> subtractorizations;
    for (int i = 0; i < lower.size(); i++) {
        for (int j = 0; j < upper.size(); j++) {
            if (upper[j] - lower[i] <= N) 
                subtractorizations.insert(upper[j] - lower[i]);
        }
    }

    int numssubtractorizations = (N % 2 == 0) ? 
                            (subtractorizations.size() - 1) : 
                            subtractorizations.size();

    return numssubtractorizations;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        cout << "Case #" << t << ": " << solve(N) << endl;
    }

    return 0;
}
