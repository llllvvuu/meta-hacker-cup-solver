
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

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void generate_primes(vector<bool>& sieve, vector<int>& primes, int N) {
    for (int i = 2; i <= N; i++) {
        sieve[i] = true;
    }
    for (int i = 2; i * i <= N; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<bool> sieve(N + 1);
        vector<int> primes;
        generate_primes(sieve, primes, N);
        int count = 0;
        for (int i = 1; i < primes.size(); i++) {
            for (int j = 0; j < i; j++) {
                int diff = primes[i] - primes[j];
                if (diff >= 2 && is_prime(diff) && diff <= N) {
                    count++;
                }
            }
        }
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
