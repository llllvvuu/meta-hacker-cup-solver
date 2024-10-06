
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
const int MAX_N = 10000000;
int N;
bool is_prime[MAX_N + 1];
std::vector<int> primes;

void preprocess() {
    fill(is_prime, is_prime + MAX_N + 1, true);
    for (int i = 2; i <= MAX_N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    preprocess(); // Sieve pre-processing

    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t) {
        std::cin >> N;
        std::vector<bool> is_subtract(MAX_N, false);
        std::vector<int> even, odd;
        int count = 0;

        for (int p : primes) {
            if (p >= N) break;
            if (p == 2) even.push_back(N - 2);
            else odd.push_back(N - p);

            for (int k : (p == 2 ? odd : even)) {
                if (k > N) break;
                if (is_prime[k]) count += !is_subtract[k]-- && k > 1;
            }
        }
        std::cout << "Case #" << t << ": " << count << std::endl;
    }

    return 0;
}
