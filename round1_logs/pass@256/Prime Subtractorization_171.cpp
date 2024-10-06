
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
#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t--) {
        size_t n;
        std::cin >> n;
        std::vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false; // 0 and 1 are not prime
        for (int i = 2; i * i <= n; ++i) { // Run Sieve
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        size_t answer = 0;
        for (int i = 2; i <= n; ++i) {
            if (primes[i]) {
                for (int j = i + 2; j <= n; j += 2) { // consider only odd numbers
                    if (primes[j] && primes[j - i]) {
                        answer++;
                        break; // Found one valid j for ith prime
                    }
                }
            }
        }
        std::cout << "Case #": " << t+1 << ": " << answer << "\n";
    }

    return 0;
}
