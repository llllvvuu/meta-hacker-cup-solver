
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

bool is_prime[10000001];
vector<int> primes;

void sieve(int N) {
    fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
    }

    // store all primes up to N in a vector
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) 
            primes.push_back(i);
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        sieve(N);
        int count = 0;

        // Check primes less than N
        for(int p : primes) {
            if (p < N && is_prime[N - p])
                count++; 
        }

        cout << "Case #" << t << ": " << count << endl;
        primes.clear(); // clear primes vector for the next test case
    }

    return 0;
}
