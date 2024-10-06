
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
#include <cmath>

using namespace std;

vector<bool> sieve(int N) {
    vector<bool> is_prime(N+1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p*p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p*p; i <= N; i += p) {
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}

int count_subtractorizations(int N) {
    vector<bool> is_prime = sieve(N);
    vector<int> primes;
    for (int i = 1; i <= N; i++) if (is_prime[i]) primes.push_back(i);
    int n = primes.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = primes[i] - primes[j];
            if (diff > 0 && is_prime[diff]) ans++;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
    }
    return 0;
}
