
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
#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX_N = 10000000;

vector<bool> sieve_primes;
vector<int> primes;

void generate_primes(int n) {
    sieve_primes = vector<bool>(n + 1, true);
    sieve_primes[0] = sieve_primes[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (sieve_primes[p]) {
            for (int i = p * p; i <= n; i += p) {
                sieve_primes[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (sieve_primes[i]) {
            primes.push_back(i);
        }
    }
}

int count_n_subtractorizations(int n) {
    generate_primes(n);
    unordered_set<int> differences;
    for (int p1 : primes) {
        for (int p2 : primes) {
            if (p1 > p2) {
                break;
            }
            differences.insert(p1 - p2);
        }
    }
    int count = 0;
    for (auto d : differences) 
        if (d > 0 && sieve_primes[d])
            count++;
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << count_n_subtractorizations(n) << endl;
    }
    return 0;
}
