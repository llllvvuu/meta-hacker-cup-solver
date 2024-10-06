
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

vector<int> sieve(int N) {
    vector<bool> is_prime(N + 1, true);
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> primes = sieve(N);
        vector<int> subtractorizations;

        for (size_t i = 0; i < primes.size(); i++) {
            for (size_t j = i + 1; j < primes.size(); j++) {
                if (primes[j] - primes[i] <= N) {
                    subtractorizations.push_back(primes[j] - primes[i]);
                }
            }
        }
        
        sort(subtractorizations.begin(), subtractorizations.end());
        subtractorizations.erase(unique(subtractorizations.begin(), subtractorizations.end()), subtractorizations.end());
        cout << "Case #" << t << ": " << subtractorizations.size() << endl;
    }
    return 0;
}
