
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
#include <vector>
using namespace std;

const int MAXN = 10000000;

bitset<MAXN> is_prime;

vector<int> primes;

void sieve(int N) {
    is_prime = bitset<MAXN>(true);
    is_prime[0] = is_prime[1] = false; 

    for (int i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= N; i++)
        if (is_prime[i]) primes.push_back(i);
}

vector<int> generate_subtractorizations(int N) {
    sieve(N);

    vector<int> diffs;

    // For each prime p
    for (int p : primes) {
        // For each q <= p
        for (int q : primes) {
            if (q >= p) break;
            int diff = p - q;
            if (diff <= N) {
                diffs.push_back(diff);
            }
        }
    }
    return diffs;
}

int count_unique(vector<int> &vec) {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return static_cast<int>(vec.size());
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        vector<int> sub = generate_subtractorizations(N);
        cout << "Case #" << i << ": " << count_unique(sub) << endl;
    }
    return 0;
}
