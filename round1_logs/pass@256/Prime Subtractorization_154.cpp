
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
#include <cstdio>
#include <cstring>
#include <vector>

const int MAXN = 10000000;
int P[MAXN + 1] = {}, sz;

std::vector<int> primes;

void getprimes() {
    for (int i = 2; i <= MAXN; i++) {
        if (P[i] == 0) P[i] = i, primes.push_back(i);
        for (int j = 0; j < sz && primes[j] <= P[i] && i * primes[j] <= MAXN; j++)
            P[i * primes[j]] = primes[j];
        sz++;
    }
}

int main() {
    getprimes();
    int T;
    std::scanf("%d", &T);
    int N;
    for (int t = 1; t <= T; t++) {
        std::scanf("%d", &N);
        int ans = 0;
        for (int i = 0; i < (int)primes.size() && primes[i] <= N; i++) {
            if (N - primes[i] >= primes[i] && P[N - primes[i]] == N - primes[i])
                ans++;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
