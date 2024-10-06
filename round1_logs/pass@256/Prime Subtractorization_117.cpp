
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
#include <cmath>

const int MAX_N = 10000005;

bool is_prime[MAX_N];

void SieveOfEratosthenes(int N) {
    fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * 2; i <= N; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

int solve(int N) {
    SieveOfEratosthenes(N);
    int subtractorizations = 0;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i] && is_prime[N - i]) {
            subtractorizations++;
            if (N / 2 + 1 < i) break;
        }
    }
    return subtractorizations;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
