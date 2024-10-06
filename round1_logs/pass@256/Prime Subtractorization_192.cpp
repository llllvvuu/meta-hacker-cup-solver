
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

vector<int> generate_primes(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i])
            primes.push_back(i);
    }
    return primes;
}

int subtractorizations(int N, vector<int>& primes) {
    set<int> set_primes = set<vector<int>::iterator>(primes.begin(), primes.end());
    int count = 0;
    for (int prime : primes) {
        if (set_primes.count(N - prime)) {
            count++;
        }
    }
    // Special case for N prime
    if (set_primes.count(N)) count++;
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> primes = generate_primes(N);
        cout << "Case #" << t << ": " << subtractorizations(N, primes) << endl;
    }
    return 0;
}
