
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

const int MAX = 10000000;
vector<int> primes;
vector<bool> sieve;

void sieve_of_eratosthenes(int max) {
    sieve.resize(max + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= max; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= max; j += i) {
                sieve[j] = false;
            }
        }
    }
    for (int i = 1; i <= 10000000; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
}

int nsubtractorizations(int n) {
    int count = 0;
    for (int prime: primes) {
        if (prime > n) {
            break;
        }
        if (sieve[n - prime]) {
            count++;
        }
    }
    return count;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    sieve_of_eratosthenes(MAX);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        cout << "Case #" << i << ": " << nsubtractorizations(N) << endl;
    }
    return 0;
}
