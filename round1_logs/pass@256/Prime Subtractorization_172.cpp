
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

const int MAX_N = 10000000;

bool is_prime[MAX_N + 1]; 
int prefix_sum[MAX_N + 1];

// Sieve of Eratosthenes to generate primes till limit
void sieve(int limit){
    fill(is_prime, is_prime + limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;
        }
    }
    prefix_sum[0] = is_prime[0];
    for (int i = 1; i <= limit; i++)
        prefix_sum[i] = prefix_sum[i - 1] + is_prime[i];
}

int main() {
    int T;
    cin >> T;
    sieve(MAX_N);
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int count = 0;
        for (int p = 2; p <= N; p++) {
            if (is_prime[p]) {
                int q_limit = N - p;
                int q_count = prefix_sum[q_limit];
                count += q_count;
            }
        }
        //Subtract extra counts where p + p <= N
        count -= (N / 2);
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
