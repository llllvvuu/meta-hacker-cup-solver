
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
#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> prime(n + 2, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<bool> prime = sieve(n);
        vector<bool> can_be_subtractorized(n + 1, false);
        int subtractorizations = prime[2] ? 1 : 0; // Only add 2 if 2 can be generated and is prime
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= i; j++) {
                if (prime[i] && prime[j] && prime[i - j]) {
                    can_be_subtractorized[i - j] = true;
                }
            }
        }
        for (int i = 3; i <= n; i++) {
            if (can_be_subtractorized[i]) {
                subtractorizations++;
            }
        }
        cout << "Case #" << i << ": " << subtractorizations << '\n';
    }
    return 0;
}
