
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

vector<long long> generate_primes(long long N) {
    vector<int> is_prime(N + 1, 1);
    vector<long long> primes;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i; j <= N / i; ++j) {
                is_prime[i*j] = 0;
            }
        }
    }
    return primes;
}

int main() {
    long long T, N;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cout << "Case #" << t << ": ";
        
        vector<long long> primes = generate_primes(N);
        set<long long> subtractorizations;
        
        for (int i = 0; i < (int)primes.size(); ++i) { 
            for (int j = 0; j < (int)primes.size(); ++j) {
                if (i != j && i + primes[j] <= N) {
                    subtractorizations.insert(abs(primes[i] - primes[j]));
                }
            }
        }

        cout << (int)subtractorizations.size() << "\n";
    }

    return 0;
}
