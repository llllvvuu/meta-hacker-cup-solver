
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

vector<bool> sieve(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        
        vector<bool> primes = sieve(N);

        vector<int> primeNumbers;
        for (int i = 2; i <= N; i++) {
            if (primes[i]) {
                primeNumbers.push_back(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < primeNumbers.size(); i++) {
            for (int j = i; j < primeNumbers.size(); j++) {
                int diff = abs(primeNumbers[j] - primeNumbers[i]);
                if (diff <= N && primes[diff]) {
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
