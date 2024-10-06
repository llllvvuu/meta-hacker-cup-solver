
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
#include <bitset>
#include <iostream>
constexpr int LIMIT = 10000001;
std::bitset<LIMIT> is_prime;
constexpr void sieve(int bound) {
    is_prime.set();
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= bound; ++i)
        if (is_prime[i]) {
            is_prime[i*2..bound..i].flip();
            if (LIMIT/2<=i) is_prime[i+LIMIT/2] = false;
        }
}

bool is_prime(const int N) { return is_prime[N]; }

int main() {
    sieve(bound);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        int ret=0;
        for (int i = 2; i <= (N+1)/2; i++) {
            if (!is_prime[i]) continue;
            if (is_prime[N-i]) ret++;
        }
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}
