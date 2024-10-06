
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
#include <algorithm>

using namespace std;

vector<int> sieve(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int countSubtractorizations(int N) {
    if (N < 5) {
        return N > 2 ? 1 : 0; // Directly return count for N < 5
    }

    vector<int> primes = sieve(N);
    vector<int> diff;

    for (int i = 0; i < primes.size(); i++) {
        for (int j = 0; j < i; j++) {
            int candidate = primes[i] - primes[j];
            if (1 <= candidate && candidate <= N) {
                diff.push_back(candidate);
            }
        }
    }

    // To get count of unique values (deduplicate), we use set
    set<int> unique_differences(diff.begin(), diff.end());
    return unique_differences.size();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << countSubtractorizations(N) << endl;
    }
    return 0;
}
