
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
#include <algorithm>
#include <iostream>
using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval(int s, int e) {
        start = s;
        end = e;
    }
};

const int max_n = 10000001;

bool is_prime[max_n];

void prime_sieve(int N_0) {
    fill(is_prime, is_prime + N_0, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int n = 2; n * n < N_0; n++) {
        if (is_prime[n]) {
            for (int k = n * n; k < N_0; k += n) {
                is_prime[k] = false;
            }
        }
    }
}

vector<int> prime_diff(const vector<int>& primes) {
    auto sz = primes.size();
    vector<int> ans;
    for (int i = 2; i < sz; i++) {
        ans.push_back(primes[i] - primes[i - 2]);
    }
    for (int i = 3; i < sz; i++) {
        ans.push_back(primes[i] - primes[i - 3]);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int N;
        cin >> N;
        prime_sieve(N + 1);

        vector<int> primes;
        for (int i = 1; i <= N; i++) {
            if (is_prime[i]){
                primes.push_back(i);
            }
        }

        vector<int> diffs = prime_diff(primes);

        long result = 0;
        vector<int> counted(max_n + 2, 0);
        for (int diff: diffs) {
            if (diff <= N && counted[diff] < 2) {
                counted[diff] = 1;
                result += 1;
            }
        }
        cout << "Case #" << test_case << ": " << result << "\n";
    }
    return 0;
}
