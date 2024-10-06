
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

bool sieve(size_t n, vector<bool> &is_prime) {
    is_prime.resize(n+1, true);
    is_prime[0] = false, is_prime[1] = false;
    for (size_t i = 2; i <= n; ++i) {
        for (size_t j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
    return true;
}

int n_subtractorizations(int n) {
    vector<bool> is_prime;
    sieve(n, is_prime);

    vector<int> primes;
    int subtract = 0;
    for(int i =2; i <= n; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }

    for (int i = 0 ; i < primes.size(); ++i) {
        for (int j = i + 1 ; j < primes.size() ; ++j) {
            if(is_prime[primes[j] - primes[i]])
            {
                subtract++;
            }
        }
    }
    return subtract;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << n_subtractorizations(n) << endl;
    }
    return 0;
}
