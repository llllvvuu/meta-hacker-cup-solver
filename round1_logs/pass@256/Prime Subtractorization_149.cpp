
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
#include <vector>
#include <set>
using namespace std;

// Function to generate primes up to N using Sieve of Eratosthenes
vector<bool> sieve(int N) {
    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p) 
                is_prime[i] = false;
        }
    }
    return is_prime;
}

int numberOfNsubtractorizations(int N) {
    vector<bool> primes = sieve(N);
    vector<int> primes_list;
    set<int> ans;

    // Push all prime numbers up to N to a list
    for (int i = 2; i <= N; i++) {
        if (primes[i]) primes_list.push_back(i);
    }

    // Calculate differences and filter
    for (int i = 0; i < primes_list.size(); i++) {
        for (int j = i; j < primes_list.size(); j++) {
            int diff = primes_list[i] - primes_list[j];
            if (diff > 0 && primes[diff] && diff <= N) {
                ans.insert(diff);
            }
        }
    }
    return ans.size();
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        cout << "Case #" << t << ": " << numberOfNsubtractorizations(N) <<endl;
    }
}
