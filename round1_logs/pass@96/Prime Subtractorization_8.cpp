
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
#include <bitset>
using namespace std;

// Function to generate all primes up to N using Sieve of Eratosthenes
vector<int> gen_primes(int N) {
    bitset<10000005> is_prime;
    vector<int> primes;
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= N; i++) {
        if (is_prime[i])
            primes.push_back(i);
        for (auto p: primes) {
            int n = p * i;
            if (n > N) break;
            is_prime[n] = false;
            if (i % p == 0) break;
        }
    }
    return primes;
}

// Function to solve a single test case
int count_subtractorizations(int N) {
    auto primes = gen_primes(N);
    bitset<10000005> prime_set;
    for (auto p: primes) 
        prime_set[p] = true;

    int count = 0;
    for (int p : primes) {
        if (prime_set[N - p])
            count++;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        cout << count_subtractorizations(N) << endl;
    }
    return 0;
}
