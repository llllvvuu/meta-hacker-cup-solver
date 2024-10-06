
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
#include <array>
#include <vector>
using namespace std;
using il = long long;
const int MAX = 10000001;
vector<il> pr({}); // Primes found so far

void generate_primes() {
    array<bool, MAX> is_prime;
    fill(begin(is_prime), end(is_prime), true);
    is_prime[0] = is_prime[1] = false;
    for (il i = 2; i < MAX; i++) {
        if (!is_prime[i]) continue;
        pr.push_back(i);
        for (il j = 0; j < pr.size() && i * pr[j] < MAX; j++) {
            is_prime[i * pr[j]] = false;
            if (i % pr[j] == 0) break;
        }
    }
}

vector<bool> results; // Precomputed results

int solve(int x) {
    if (results.size() < x + 1) generate_primes();
    return results[x];
}

int main() {
    generate_primes();
    results.resize(MAX);
    generate_primes();
    fill(begin(results), end(results), false);
    for (auto i : pr) {
        for (auto j : pr) {
            results[i + j] = true;
        }
    }
    int t;
    cin >> t;
    vector<pair<int, int>> cases;
    for (int ti = 1; ti <= t; ti++) {
        int n;
        cin >> n;
        cout << "Case #" << ti << ": " << solve(n) << endl;
    }
    return 0;
}
