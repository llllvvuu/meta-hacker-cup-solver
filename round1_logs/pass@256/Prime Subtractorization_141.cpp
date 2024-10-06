
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

static const int MAX_N = 10000000;
bitset<MAX_N + 5> isprime;
int primes[MAX_N + 2];

// Sieve of Eratosthenes
void sieve() {
    isprime.set();
    for(int i = 3; i * i <= MAX_N; i++) { 
        if(isprime[i]) {
            for(int j = i * i; j <= MAX_N; j += 2 * i) {
                isprime[j] = 0;
            }
        }
    }
    
    primes[0] = 2;
    int add = 1;
    for(int i = 3; i <= MAX_N; i += 2) {
        if(isprime[i]) {
            primes[add] = i;
            add++;
        }
    }
}

int countSubtractorizations(int N) {
    int count = 0;
    for (int i = 1; primes[i] <= N; i++) {
        for (int j = i; primes[j] <= N; j++) {
            prime_diff = primes[j] - primes[i];
            if (prime_diff <= N && isprime[prime_diff]) count++;
        }
    }
    return count;
}

int main() {
    sieve();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << countSubtractorizations(N) << endl;
    }
    return 0;
}
