
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
#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

// Returns a vector of booleans primes with primes[i] == true if i is prime
vector<bool> sieve(int N) {
    vector<bool> primes(N + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (primes[i])
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
    return primes;
}

int solve(int N) {
    vector<bool> primes = sieve(N);
    bitset<10000001> prime_check;
    for(int i = 0; i <= N; i++) {
        prime_check[i] = primes[i];
    }
    int count = 0;
    for(int p = 2; p <= N; p++) {
        if(primes[p] && prime_check[N-p]) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin>>T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin>>N;
        cout << "Case #" << t << ": " << solve(N) << '\n';
    }
    return 0;
}
