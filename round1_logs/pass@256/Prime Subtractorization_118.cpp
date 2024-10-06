
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

const int MAX_N = 10000000;

vector<bool> is_prime(MAX_N+1, true);
vector<int> primes;

// Sieve of Eratosthenes to generate all primes <= N
void sieve(int N) {
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not primes
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    sieve(N);
    
    // Count how many primes have a prime difference <= N
    vector<bool> subtractorizations(MAX_N+1, false); 
    for (int i = 0; i < primes.size(); i++) {
        for (int j = 0; j < i; j++) {
            int diff = primes[i] - primes[j];
            // Ensure diff is less than or equal to N, and itself prime.
            if (1 < diff && diff <= N && is_prime[diff]) {
                subtractorizations[diff] = true;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && subtractorizations[i]) {
            count++;
        }
    }
    
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
