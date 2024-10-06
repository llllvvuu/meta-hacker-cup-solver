
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
    vector<bool> primes(n+1, true); 
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

int count_subtractorizations(int n) {
    vector<bool> primes = sieve(n);
    vector<int> diff_count(n, 0);
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            for (int j = i + 1; j <= n; j++) {
                if (primes[j]) {
                    int diff = j - i;
                    if (diff >= 2 && diff <= n) ++diff_count[diff];
                }
            }
        }
    }
    int result = 0;
    for (int x: diff_count) if (x > 0) result++;
    return result;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": " << count_subtractorizations(n) << "\n";
    }
}
