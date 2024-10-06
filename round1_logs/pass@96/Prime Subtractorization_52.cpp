
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

bool sieve(vector<bool>& primes, int n) {
    for (int i = 2; i*i <= n; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return true;
}

vector<int> generatePrimes(int limit) {
    vector<bool> primes(limit+1, true);
    sieve(primes, limit);
    vector<int> ret;
    for (int i = 2; i <= limit; i++) {
        if (primes[i]) ret.push_back(i);
    }
    return ret;
}

int countNSubtractorizations(int n) {
    vector<int> primes = generatePrimes(n);
    int subtractorizations = 0;
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            int diff = primes[j] - primes[i];
            if (diff > n || diff == 0) break;
            if (primes[i] - 2 == diff || 
                    binary_search(primes.begin(), primes.end(), diff)) {
                subtractorizations++;
                break;
            }
        }
    }
    return subtractorizations;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        int n;
        cin >> n;
        cout << countNSubtractorizations(n) << endl;
    }
}
