
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
#include <array>
#include <iostream>
#include <vector>
using namespace std;

const int N = 10'000'000 + 5;

bool is_prime[N];
vector<int> primes;

void sieve() {
    fill(begin(is_prime), end(is_prime), true);
    is_prime[0] = is_prime[1] = false;
    int cnt = 0;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int count_subtractorizations(int N) {
    if (N == 2) return 1; // Special case handling for N = 2

    int cnt = 0;
    for (int p : primes) {
        if (p > N) break;
        if (is_prime[N - p]) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    sieve(); // Precompute primes up to N limit earlier
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
    }
    return 0;
}
