
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
#include <set>
#include <cmath>
const int maxn = 10000000;
bool prime[maxn + 1];
void sieve(int N) {
    std::fill(prime, prime + 1 + N, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p <= N; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= N; i += p) {
                prime[i] = false;
            }
        }
    }
}

int main() {
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        std::cin >> N;
        sieve(N);
        std::set<int> result;
        std::vector<int> primes;
        for (int i = 2; i <= N; i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }
        const int size = primes.size();
        int count = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                int diff = std::abs(primes[i] - primes[j]);
                if (diff > 1 && prime[diff]) {
                    result.insert(diff);
                }
            }
        }
        std::string separator = "Case #" + std::to_string(t) + ": ";
        std::cout << separator << result.size() << std::endl;
    }
    return 0;
}
