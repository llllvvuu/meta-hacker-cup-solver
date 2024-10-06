
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
#include <set>
#include <cmath>
using namespace std;

vector<bool> is_prime;
vector<int> primes;

void sieve(int N) {
    is_prime.assign(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

int count_subtractorizations(int N) {
    set<int> subtractorizations;
    sieve(N);
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            if (primes[j] - primes[i] <= N && is_prime[primes[j] - primes[i]])
                subtractorizations.insert(primes[j] - primes[i]);
        }
    }
    return subtractorizations.size();
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
    }
}
