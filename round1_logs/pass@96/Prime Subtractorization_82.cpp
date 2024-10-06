
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
#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 10000001; // Slightly larger than 10{,}000{,}000

bool is_prime[N_MAX];
vector<int> primes;

void sieve() {
    fill(is_prime, is_prime + N_MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N_MAX; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N_MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int find_n_subtractorizations(int N) {
    sieve();
    vector<int> cnt(N + 1, 0); // Each index represents a possible N-subtractorization
    for (int p : primes) {
        if (p >= N) break; // Primes larger than N cannot form valid differences
        if (p == 2) {
            cnt[N - 2]++; // 2 can be subtracted from N to form the difference
        }
        if (N > p) {
            cnt[N - p]++; // N-p is a potential subtractorization
        }
    }
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (cnt[i] == 1) { // A valid prime difference must appear exactly once
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    sieve(); // Prepare primes up-front
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << find_n_subtractorizations(N) << endl;
    }
    return 0;
}
