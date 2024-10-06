
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
#include<iostream>
#include<vector>
using namespace std;

const int MAX_N = 10000000;

vector<int> primes;

void GeneratePrimes(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p <= N; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (int q = p * p; q <= N; q += p) {
                is_prime[q] = false;
            }
        }
    }
}

vector<int> FindSubtractorizations(int N) {
    vector<int> result;
    vector<bool> subtractorizations(N + 1, false);
    for (int p : primes) {
        for (int q : primes) {
            if (p >= q) break;
            if (p + q > N) break;
            subtractorizations[p + q] = true;
        }
    }
    for (int i = 2; i <= N; i++) {
        if (subtractorizations[i] && subtractorizations[N - i] && N - i >= i) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    GeneratePrimes(MAX_N);
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> subtractorizations = FindSubtractorizations(N);
        cout << "Case #" << t << ": " << subtractorizations.size() << endl;
    }
    return 0;
}
