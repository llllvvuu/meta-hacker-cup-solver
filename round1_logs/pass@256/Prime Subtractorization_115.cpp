
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
#include <bitset>
using namespace std;

bitset<10000001> sieve_prime;
vector<int> primes;
void sieve(int N) {
    sieve_prime.set();
    sieve_prime[0] = sieve_prime[1] = 0;
    for (int i = 2; i <= N; ++i) {
        if (sieve_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= N; j += i) {
                sieve_prime[j] = 0;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        sieve(N);
        bitset<10000001> subtractorization;
        int result = 0;
        for (int i = 0; i < primes.size(); i++) {
            for (int j = 0; j < primes.size(); j++) {
                int diff = primes[j] - primes[i];
                if (diff <= N && diff > 0 && sieve_prime[diff]) {
                    subtractorization[diff] = 1;
                    result++;
                }
            }
        }
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
