
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
bool is_prime[MAX_N + 1]; // Sieve array
vector<int> primes; // Store all primes up to MAX_N

void sieve() {
    fill(is_prime, is_prime + MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= MAX_N; j += i)
                is_prime[j] = false;
        }
    }
}

int N;
vector<int> prefix_primes;

void preprocess() {
    sieve();
    prefix_primes.resize(primes.size() + 1);
    for (int i = 0; i < primes.size(); i++)
        prefix_primes[i + 1] = prefix_primes[i] + primes[i];
}

int solve_case(int N) {
    int lo = 0, hi = primes.size() - 1;
    int count = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (primes[mid] * 2 <= N) {
            count += mid - lo + 1;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        cout << "Case #" << t << ": " << solve_case(N) << endl;
    }
    return 0;
}
