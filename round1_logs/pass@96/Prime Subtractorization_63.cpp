
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
#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 10000000;

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int subtractorizations(int N) {
    if (N == 2) return 0;
    if (N == 3) return 1;

    vector<int> primes = sieve(N);
    if (primes.back() < N) primes.push_back(N); // Ensure N is included if prime

    int cnt = 0;
    if (N % 2 == 0) { // Even N
        cnt += 1; // Subtract 2 (the only subtractorization)
        for (int i = 0, j = 1; j < primes.size(); j++) {
            while (primes[i] + primes[j] <= N) i++;
            if (primes[i] + primes[j] == N) cnt++;
        }
    } else { // Odd N
        for (int i = 0, j = 1; primes[j] < N; j++) {
            while (primes[i] + primes[j] <= N) i++;
            if (primes[i] + primes[j] == N) cnt++;
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << subtractorizations(N) << endl;
    }
    return 0;
}
