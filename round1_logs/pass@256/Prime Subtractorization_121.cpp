
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
using namespace std;

const int MAXN = 10000010;

// Sieve of Eratosthenes
vector<int> primes;

vector<int> sieve_prime() {
    vector<int> isprime(MAXN, 1);
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= MAXN; ++i)
        if (isprime[i])
            for (int j = i * i; j < MAXN; j += i)
                isprime[j] = 0;
    for (int i = 0; i < MAXN; ++i)
        if (isprime[i]) primes.push_back(i);
    return isprime;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    vector<int> isprime = sieve_prime();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        vector<bool> subtractorizations(N, false);
        for (int i = 0; i < primes.size() && primes[i] <= N; i++) {
            for (int j = 0; j < primes.size() && primes[j] <= N; j++) {
                int diff = primes[i] - primes[j];
                if (diff > 0 && diff < N && isprime[diff]) subtractorizations[diff] = true;
            }
        }
        cout << count(subtractorizations.begin(), subtractorizations.end(), true) << endl;
    }
    return 0;
}
