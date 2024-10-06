
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
#include <bitset>
#include <iostream>
using namespace std;

const int MX = 10000005;
bitset<MX> is_prime;

// Sieve of Eratosthenes preprocessing.
void sieve() {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < MX; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MX; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    sieve(); // Precomputation happens here.

    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        int answer = 0;
        for (int p1 = 2; p1 <= N; p1++) {
            if (!is_prime[p1]) continue; // Skip non-primes
            for (int p2 = p1 - 1; p2 >= 2; p2--) {
                if (is_prime[p2] && (p1 - p2 <= N)) {
                    answer++;
                    break;
                }
            }
        }

        cout << "Case #" << t << ": " << (answer / 2) << '\n'; // Each diff counted twice.
    }
    return 0;
}
