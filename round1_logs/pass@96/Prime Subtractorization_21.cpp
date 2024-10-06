
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

vector<int> smallest_divisor;

void sieve(int N) {
    smallest_divisor.assign(N + 1, 0);
    smallest_divisor[1] = 1; // 1 is not prime

    for (int i = 2; i <= N; i++) {
        if (smallest_divisor[i] == 0) {
            smallest_divisor[i] = i; // i is prime
            for (long long j = (long long)i * i; j <= N; j += i) {
                if (smallest_divisor[j] == 0) {
                    smallest_divisor[j] = i;
                }
            }
        }
    }
}

bool is_prime(int num) {
    return smallest_divisor[num] == num;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        sieve(N);

        vector<int> primes;
        for (int i = 2; i <= N; i++) {
            if (is_prime(i)) {
                primes.push_back(i);
            }
        }

        int count = 0;
        for (int i = 0; i < primes.size(); i++) {
            for (int j = i + 1; j < primes.size(); j++) {
                int diff = primes[j] - primes[i];
                if (is_prime(diff)) {
                    count++;
                }
            }
        }

        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
