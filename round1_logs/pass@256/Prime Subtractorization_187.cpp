
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
using namespace std;

int T, N, sieve[10000001], result[101];
bool primes[10000001];

void build_sieve() {
    for(int i = 2; i <= N; i++) {
        if(primes[i] == true) continue;
        sieve[i] = i;
        int j = 2;
        while(i * j <= N) {
            primes[i * j] = true;
            j++;
        }
    }

    for(int i = 2; i <= N; i++) {
        if(!primes[i]) sieve[i] = sieve[i-1];
        else sieve[i] = sieve[i-1] + i;
    }
}

int main() {
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> N;
        for(int j = 1; j <= 10000000; j++) primes[j] = false;
        build_sieve();
        result[i] = sieve[N] - sieve[N/2];
    }

    for(int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": " << result[i] << '\n';
    }
    return 0;
}
