
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

const int N = 10000000; // Large enough to cover maximum N
vector<bool> is_prime(N + 1, true);
vector<int> primes;

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= N; j += i) is_prime[j] = false;
        }
    }
    for(int i = 2; i<=N; ++i)
        if(is_prime[i])
            primes.push_back(i);
}

int main()
{
    sieve();
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int ans = 0;
        int idx = lower_bound(primes.begin(), primes.end(), N) - primes.begin();

        for(int i = idx-1; i>=0; --i) {
            if(primes[i] >= N)
                continue;
            if(binary_search(primes.begin(), primes.end(), N - primes[i]))
                ans++;
        }

        cout<< "Case #"<< t << ": " << ans << "\n";
    }
    return 0;
}
