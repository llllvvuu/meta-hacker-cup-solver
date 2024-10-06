
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
#include <unordered_set>
using namespace std;

int primes[10000001]; // true if i-th index is prime
unordered_set<int> prime_differences;

void sieve(int N) {
    for (int i = 2; i <= N; i++) {
        primes[i] = true;
    }
    for (int i = 2; i * i <= N; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= N; j += i) {
                primes[j] = false;
            }
        }
    }
    // Calculate prime differences and store them
    for (int i = 2; i <= N; i++) {
        if (primes[i]) {
            for (int j = i; j <= N; j++) {
                if (primes[j]) {
                    prime_differences.insert(abs(j - i));
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    sieve(10000000); 

    for(int t = 1; t <= T; t++) {
        int N;
        int result = 0;
        cin >> N;
        for (auto diff : prime_differences) {
            if (diff <= N && primes[diff]) {
                result++;
            }
        }
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
