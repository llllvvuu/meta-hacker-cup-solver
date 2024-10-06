
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
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void SieveOfEratosthenes(int N, vector<bool>& primes) {
    fill(primes.begin(), primes.end(), true);
    primes[0] = primes[1] = false;
    for (int p = 2; p * p <= N; p++) 
        if (primes[p])
            for (int i = p * p; i <= N; i += p) primes[i] = false;
}

int subtractorizations(const int N) {
    vector<bool> primes(N + 1);
    SieveOfEratosthenes(N, primes);
    set<int> simple_diffs;

    for (int i = 2; i <= N; i++) {
        if (primes[i]) {
            for (int j = i; j <= N; j++) {
                if (primes[j] && i != j) {
                    int diff = abs(i - j);
                    if (diff <= N && diff != i && diff != j && primes[diff]) {
                        simple_diffs.insert(diff);
                    }
                }
            }
        }
    }
    return simple_diffs.size();
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
