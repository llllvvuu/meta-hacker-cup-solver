
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

bool is_prime_sieve(int n, vector<int>& primes) {
    vector<bool> sieve(n + 1, true);
    for (int i = 2; i <= n; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i)
                sieve[j] = false;
        }
    }
}

vector<int> generate_primes(int N) {
    vector<int> primes;
    is_prime_sieve(N, primes);
    return primes;
}

int count_subtractorizations(int N) {
    vector<int> primes = generate_primes(N);
    vector<bool> is_subtract(N + 1, false);
    for (size_t i = 0; i < primes.size(); ++i) {
        for (size_t j = i; j < primes.size(); ++j) {
            int diff = primes[j] - primes[i];
            if (diff > N) break;
            is_subtract[diff] = true;
        }
    }
    vector<int> subtracts(N + 1);
    for (int i = 0; i <= N; ++i) {
        if (is_subtract[i])
            subtracts[i]++;
    }
    return subtracts[N];
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
    }
    return 0;
}
