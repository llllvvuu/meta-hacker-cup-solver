
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
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000005;

bool is_prime[MAXN]; 

void sieve(int N) {
    fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p)
                is_prime[i] = false;
        }
    }
}

vector<int> getPrimes(int N) {
    vector<int> primes = {2};
    vector<bool> sieve_cache(N+1, true);
    sieve_cache[0] = sieve_cache[1] = false;
    
    for(int i = 3 ; i < N ; i += 2) {
        if(sieve_cache[i] == false) continue;
        primes.push_back(i);
        for(int j = i*i ; j <= N ; j += i) {
            sieve_cache[j] = false;
        }
    }
    return primes;
}

int main() {
    sieve(MAXN-1);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        
        cout << "Case #" << t << ": ";
        
        // Use pre-generated sieve for checking
        vector<int> primes = getPrimes(N);
        int count = 0;
        for(int i = 0 ; i < primes.size() ; i++) {
            for(int j = 0; j <= i ; j++) {
                if((primes[i] - primes[j]) > N || (primes[i] - primes[j]) <= 0) continue;
                if(is_prime[primes[i] - primes[j]]) count++;
            }
        }
        
        cout << count << endl;
    }
    return 0;
}
