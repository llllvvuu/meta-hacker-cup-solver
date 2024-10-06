
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

const int MAX_N = 10000002;
bool is_prime[MAX_N];
int sieve[MAX_N]; // To store the highest difference count for each number up to N

void preprocess_sieve() {
    fill(is_prime, is_prime + MAX_N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (!is_prime[i]) continue;
        sieve[i] = 1; //marking the number of valid differences for this prime number
        for (int j = 2 * i; j < MAX_N; j += i) {
            if (is_prime[j]) {
                ++sieve[j];
                is_prime[j] = false;
            }
        }
        // If a difference is a prime number, add it to our overall counts
        if (i > 2 && is_prime[i - 2]) sieve[i - 2]++;
    }
}

int main() {
    preprocess_sieve();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        int count = 0;
        for (int i = 1; i <= N; i++) {
            count += sieve[i];
        }
        cout << count << "\n";
    }
}
