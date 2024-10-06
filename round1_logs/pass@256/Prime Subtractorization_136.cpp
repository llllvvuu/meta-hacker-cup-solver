
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

int mp[50000050];

void sieve(int &N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p) is_prime[i] = false;
        }
    }
    vector<int> primes;
    for (int p = 0; p <= N; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
    // Fill mp with counts of prime differences
    for (int i = 0; i < primes.size(); i++) {
        for (int j = 0; j <= i; j++) {
            mp[primes[i] - primes[j]]++;
        }
    }
}

int solve(int N) {
    if (mp[0] == 0) sieve(N);
    int ans = 0; 
    for (int d = 2; d <= N; d++)  if (mp[d] && mp[d] >= 2) ans++;
    return ans; 
}
 
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
