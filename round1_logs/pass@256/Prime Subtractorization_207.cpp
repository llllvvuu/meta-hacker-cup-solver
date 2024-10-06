
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
#include <iostream>
using namespace std;

const int MAXN = 10000000;

vector<int> primes;

void sieve() {
    vector<bool> is_prime(MAXN+1, true);
    for (int p = 2; p*p <= MAXN; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= MAXN; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= MAXN; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

int main() {
    sieve();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        
        vector<int> subtractorizations;
        for (int i = 0; i < primes.size() && primes[i] <= N - 2; ++i) {
            auto it = lower_bound(primes.begin(), primes.end(), primes[i] + 2);
            for (; it != primes.end() && *it <= N ; ++it) {
                int diff = *it - primes[i];
                auto pos = lower_bound(primes.begin(), primes.end(), diff);
                if (pos != primes.end() && *pos == diff)
                    subtractorizations.push_back(diff);
            }
        }
        sort(subtractorizations.begin(), subtractorizations.end());
        subtractorizations.erase(unique(subtractorizations.begin(), subtractorizations.end()), subtractorizations.end());
        
        int count = subtractorizations.size();
        cout << count << endl;
    }
}
