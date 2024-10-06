
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
#include <bits/stdc++.h>
using namespace std;

bool is_prime[10000001];
int prime_count[10000001];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < 10000001; ++i) {
        if (is_prime[i]) {
            prime_count[i] = prime_count[i-1] + 1;
            for (int j = i * i; j < 10000001; j += i) {
                is_prime[j] = false;
            }
        } else {
            prime_count[i] = prime_count[i-1];
        }
    }
}

int main() {
    sieve();

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long N;
        cin >> N;
        int count = 0;
        for (int p = 2; p <= N; p++) {
            if (is_prime[p] && is_prime[N - p]) {
                // Avoid double counting 2 == 5 - 3 == 3 - 2
                if (N - p != p) count++;
            }
        }
        if (N > 2) count++; // Handle the case where 2 can be expressed uniquely as 3 - 1
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
