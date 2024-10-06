
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
#include<cmath>
using namespace std;

vector<int> primes;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void sieve(int n) {
    vector<bool> composite(n + 1, false);
    for (int i = 2; i <= n; ++i) {
        if (!composite[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j <= n; j += i) {
                composite[j] = true;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        sieve(N);
        int count = 0;
        for (int i = 0; i < primes.size(); ++i) {
            for (int j = i; j < primes.size(); ++j) {
                int diff = primes[i] - primes[j];
                if (diff > 0 && is_prime(diff)) {
                    count++;
                }
            }
        }
        cout << "Case #" << t << ": " << count / 2 << endl; // Each difference is counted twice
    }

    return 0;
}
