
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

const int MAXN = 1e7 + 5;

bool isPrime[MAXN];
vector<int> primes;  // List to store all primes up to N.

void sieve(int N) {
    fill(isPrime, isPrime + N + 1, true);
    primes.push_back(2);
    isPrime[0] = isPrime[1] = false;
    for (int i = 3; i * i <= N; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i + i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 5; i <= N; i += 2) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

vector<long long> prefixSumPrimes;

void calculatePrefixSumPrimes(int N) {
    prefixSumPrimes.push_back(0);
    for (long long i = 1; i < primes.size() && primes[i] <= N; ++i) {
        prefixSumPrimes.push_back(prefixSumPrimes[prefixSumPrimes.size() - 1] + primes[i]);
    }
}

int calculateCount(int N) {
    sieve(2 * N);
    calculatePrefixSumPrimes(2 * N);
    long long r = N;
    long long ans = 0;
    
    int sum = 0;
    for(int p : primes){
        if(p > r) break;
        sum += (prefixSumPrimes[end(prefixSumPrimes)-1] - prefixSumPrimes[p]);
        r = max(r - p, (long long)1); 
        ans += sum;
    }
    
    return ans - r - 1;  // Subtract r and 1 (count starts from 1)
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        int N;
        cin >> N;
        cout << "Case #" << i << ": " << calculateCount(N) << "\n";
        primes.clear();  // Clear primes list for next test case
    }
}
