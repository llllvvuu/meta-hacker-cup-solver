
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
#define MAX_N 10000000

using namespace std;

bool is_prime[MAX_N+1];

void sieve() {
    fill(is_prime, is_prime + MAX_N+1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int solve(int N) {
    vector<int> primes = {};
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    
    int count = 0;
    for (int i = 0; i < primes.size(); i++) {
        if (N - primes[i] > 0 && N - primes[i] <= MAX_N && is_prime[N - primes[i]]) {
            count++;
        }
    }
    
    // Special case for N > 2 and N even.
    if (N % 2 == 0 && N > 2) {
        count--;
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;
    sieve();
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        cout << "Case #" << i << ": " << solve(N) << endl;
    }
    return 0;
}
