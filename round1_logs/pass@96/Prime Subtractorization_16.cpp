
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

bitset<10000001> sieve;

int countNsubtractors(int N) {
    sieve.reset();
    sieve.set();
    sieve[0] = sieve[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (sieve[p]) {
            for (int i = p * p; i <= N; i += p) {
                sieve[i] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    bitset<10000001> counted;
    for (int i = 0; i < primes.size(); i++) {
        for (int j = i; j < primes.size(); j++) {
            int diff = primes[j] - primes[i];
            if (diff <= N && sieve[diff] && diff) {
                counted[diff] = true;
            }
        }
    }
    return counted.count();
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        cout << "Case #" << t << ": " << countNsubtractors(N) << endl;
    }
    return 0;
}
