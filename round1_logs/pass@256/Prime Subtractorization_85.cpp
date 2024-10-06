
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

vector<int> sieve(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int p = 2; p <= N; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (int i = p * p; i <= N; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

int count_D(int N) {
    vector<int> primes = sieve(N);
    set<int> unique;
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            unique.insert(primes[i] - primes[j]);
        }
    }
    return unique.size();
}

int main() {
    int T, N;
    cin >> T;
    vector<int> res(T);
    for (int t = 0; t < T; ++t) {
        cin >> N;
        res[t] = count_D(N);
    }
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": " << res[t] << endl;
    }
    return 0;
}
