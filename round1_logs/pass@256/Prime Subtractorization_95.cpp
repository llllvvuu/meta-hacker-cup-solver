
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
#include <set>
using namespace std;

//Sieve function to create a boolean mask indicating prime status
void sieve(vector<bool>& is_prime, int N) {
    is_prime.resize(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<bool> is_prime(N + 1);
        sieve(is_prime, N);

        set<int> subtractorizations;
        for (int i = 2; i <= N; i++) {
            if (!is_prime[i]) continue;
            for (int j = i; j <= N; j++) {
                if (!is_prime[j]) continue;
                subtractorizations.insert(abs(i - j));
            }
        }

        cout << "Case #" << t << ": " << subtractorizations.size() << endl;
    }
    return 0;
}
