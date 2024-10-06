
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
#define modulo 1000000007
#define mod 998244353

using namespace std;

bool isprime[20000500];

vector<int> primes;
int dp[10000500];
void sieve(int m) {
    fill(isprime, isprime + m + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= m; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= m; j += i) {
                isprime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(10000000);

    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        unordered_set<int> result;
  
        for(int i = 1; i < primes.size() && primes[i] <= N; i++) {
            for(int j = i - 1; primes[i] - primes[j] <= N; j--) {
                result.insert(primes[i] - primes[j]);
            }
        }
        cout << "Case #" << t << ": " << result.size() << "\n";
    }

}
