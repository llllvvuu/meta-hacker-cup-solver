
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

vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            primes.push_back(i);
        for (int j : primes) {
            int product = i * j;
            if (product > n) break;
            is_prime[product] = false;
            if (i % j == 0) break; 
        }
    }
    return primes;
}

const int MAXN = 10005000;
vector<int> primes = sieve(MAXN);

vector<int> subtractorizations;
void preprocess() {
    for (int i = 1; i < primes.size(); i++) {
        for (int j = 0; j < i; j++) {
            int diff = primes[i] - primes[j];
            if (diff <= MAXN && diff > 1) {
                subtractorizations.push_back(diff);
            }
        }
    }
}

int main() {
    preprocess();

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; cin >> N;
        vector<int> valid_subtractorizations;
        for (int i = 0; i < subtractorizations.size(); i++) {
            if (subtractorizations[i] > N) continue;
            if (N <= 3 && subtractorizations[i] == 2) valid_subtractorizations.push_back(2);
            else if (N >= 3 && subtractorizations[i] != 2) valid_subtractorizations.push_back(subtractorizations[i]);
        }
        cout << "Case #" << t << ": " << valid_subtractorizations.size() << "\n";
    }
    return 0;
}
