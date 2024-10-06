
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
#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 10000007;
bitset<MAX_N> sieve;
vector<int> primes;

void generatePrimes(int N) {
    sieve.set();
    sieve.reset(0, 2);
    for (int p = 2; p * p <= N; p++)
        if (sieve[p])
            for (int q = p * p; q <= N; q += p)
                sieve[q] = false;
    for (int p = 2; p <= N; p++)
        if (sieve[p])
            primes.push_back(p);
}

int countSubtractorizations(int N) {
    int count = 0;
    for (int i = 1; i < primes.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            int diff = primes[i] - primes[j];
            if (diff < 2) break; // Since primes[0] = 2 and cannot form a valid pair with smaller or equal primes
            if (sieve[diff])
                count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        generatePrimes(N);
        cout << "Case #" << t << ": " << countSubtractorizations(N) << endl;
    }
}
