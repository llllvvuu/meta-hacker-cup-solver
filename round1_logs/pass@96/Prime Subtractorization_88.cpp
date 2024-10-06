
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
using namespace std;

vector<int> sieve_of_eratosthenes(int N) {
    vector<bool> prime(N + 1, true);
    vector<int> primes;
    for (int p = 2; p * p <= N; p++) {
        if (prime[p]) {
            primes.push_back(p);
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
    for (int p = N / 2 + 1; p <= N; p++) {
        if (prime[p])
            primes.push_back(p);
    }
    return primes;
}

int count_N_subtractorizations(int N) {
    vector<int> primes = sieve_of_eratosthenes(N);
    vector<bool> can_be_number(N + 1, false);
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            int diff = primes[j] - primes[i];
            if (diff <= N && (diff == primes[i] || prime[diff])) {
                can_be_number[diff] = true;
            }
        }
    }
    int count = 0;
    for (bool is_subtractorization : can_be_number) {
        if (is_subtractorization) count++;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << count_N_subtractorizations(N) << endl;
    }
    return 0;
}
