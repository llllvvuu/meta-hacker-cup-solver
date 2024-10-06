
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
#include <bitset>
#include <iostream>
using namespace std;

const int MAX_N = 1e7 + 5;
bitset<MAX_N> is_prime;
vector<int> primes;

void sieve() {
    for (int i = 2; i < MAX_N; i++) {
        if (!is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j < MAX_N; j += i) {
                is_prime[j] = true;
            }
        }
    }
}

int main() {
    sieve();
    
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        int count = 0;
        for (int p : primes) {
            if (p > N)
                break;
            if (is_prime[N - p]) {
                count++;
            } // N - p is prime and within [2,N]
        }
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
