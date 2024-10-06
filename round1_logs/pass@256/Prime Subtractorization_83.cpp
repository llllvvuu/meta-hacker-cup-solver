
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

int T, N;
vector<int> dp, primes;

void compute_primes(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false; // Prime numbers sieve
    for (int i = 2; i * i <= N; i++)
        if (is_prime[i])
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
    for (int i = 2; i <= N; i++)
        if (is_prime[i])
            primes.push_back(i);
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        dp.assign(10000001, 0); // Reset dp table for next case
        cin >> N;
        compute_primes(N); 
        dp[2] = 1; // Set dp[2] to 1 for primes starting with "2"
        vector<int>& p = primes;
        int sz = p.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i; j < sz; j++) {
                int sum = p[i] + p[j];
                if (sum > N)
                    break;
                dp[sum] += 1;
            }
        }
        int result = 0;
        for (int i = 1; i <= N; i++) {
            if (dp[i] == 0)
                dp[i] = -1; // Indicate non-prime or doesn't exist
            else if (dp[i] > 0 && i <= N && primes.size())
                result += 1;
        }
        cout << "Case #" << t << ": " << result << "\n";
    }
    return 0;
}
