
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
#include <iostream>

// Sieve to generate a vector of booleans where prime[i] means whether i is prime
std::vector<bool> sieve(int n) {
    std::vector<bool> prime(n+1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}
 
int main() {
    int T;
    std::cin >> T;
    std::vector<int> precomputed = { 0, 0, 1, 2, 2, 3 };
    for (int t = 1; t <= T; t++) {
        int N;
        std::cin >> N;
        std::cout << "Case #" << t << ": ";
 
        if (N < precomputed.size()) {
            std::cout << precomputed[N] << std::endl;
            continue;
        }
 
        auto prime = sieve(N);
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += prime[i];
        }
 
        // Only keep the primes we care about
        ans -= (N-1) / 2;
 
        std::cout << ans << std::endl;
    }
    return 0;
}
