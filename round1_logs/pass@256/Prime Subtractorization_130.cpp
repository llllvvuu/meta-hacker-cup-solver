
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
#include <unordered_set>
using namespace std;

int main() {
    // Precompute primes <= MAXN using sieve of Eratosthenes
    const int MAXN = 1e7;
    vector<bool> is_prime(MAXN, true);
    vector<int> primes;
    for (int i = 2; i < MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Calculate all prime differences and store them in a set
    unordered_set<int> prime_diffs;
    for (int i = 0; i < primes.size(); ++i) {
        for (int j = i; j < primes.size(); ++j) {
            int diff = primes[j] - primes[i];
            if (diff <= MAXN) {
                prime_diffs.insert(diff);
            }
        }
    }

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        int count = 0;
        for (auto& diff : prime_diffs) {
            if (diff <= N) ++count;
        }
        cout << count << endl;
    }
    return 0;
}
