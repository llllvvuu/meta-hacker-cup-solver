
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

void sieveOfEratosthenes(int N, vector<bool>& isPrime) {
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not primes
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i] == true) {
            for (int j = i * 2; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int subtractorizations(int N) {
    vector<bool> isPrime(N + 1, true);
    sieveOfEratosthenes(N, isPrime);
    
    int count = 0;
    isPrime[1] = false; // Reset case involving non-prime diffs.
    if (N >= 2) count += (isPrime[2] && isPrime[3]); // difference 1 special case
    
    for (int diff = 2; diff <= N - 2; diff += 2) {
        bool isEvenPrimeOk = isPrime[2 + diff] && (diff != 2);
        bool is3PrimeOk = isPrime[3 + diff];
        if (isEvenPrimeOk || is3PrimeOk) {
            count++;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << subtractorizations(N) << endl;
    }

    return 0;
}
