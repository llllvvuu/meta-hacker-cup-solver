
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
#include <vector>
using namespace std;

bool sieve[10000001] = {true, true};
vector<int> primes;

void generatePrimes(int N) {
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (int j = 2 * i; j <= N; j += i) {
            sieve[j] = true;
        }
    }
}

int subtractorizations(int N) {
    generatePrimes(N);
    int count = 0;
    for (int p : primes) {
        bool isValid = false;
        for (int p1 : primes) {
            if (p1 <= p) break;
            int p2 = p1 - p;
            if (p2 < 2) break;
            if (binary_search(primes.begin(), primes.end(), p2)) {
                isValid = true;
                break;
            }
        }
        if (isValid) count++;
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << subtractorizations(N) << endl;
    }
    return 0;
}
