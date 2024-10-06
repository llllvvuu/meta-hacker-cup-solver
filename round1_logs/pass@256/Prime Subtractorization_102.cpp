
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

const int MAXN = 10000000;
bool is_prime[MAXN];
vector<bool> precomputed_is_prime(MAXN);

void sieve() {
    for (int i = 2; i < MAXN; i++) is_prime[i] = true;
    for (int i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAXN; j += i) is_prime[j] = false;
        }
    }
    for (int i = 0; i < MAXN; i++) precomputed_is_prime[i] = is_prime[i];
}

int solve(int N) {
    if (N < 3) return 0;
    sieve();
    vector<int> subtractorizations;
    for (int q = N; q >= 2; --q) {
        if (is_prime[q]) {
            for (int p = q - 2; p >= 2 && p > q - N; --p) {
                if (is_prime[p] && is_prime[q - p]) {
                    subtractorizations.push_back(q - p);
                    break;
                }
            }
        }
    }
    // Remove duplicates
    sort(subtractorizations.begin(), subtractorizations.end());
    subtractorizations.erase(unique(subtractorizations.begin(), subtractorizations.end()), subtractorizations.end());
    return subtractorizations.size();
}

int main() {
    int T;
    sieve();
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        is_prime = precomputed_is_prime;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
