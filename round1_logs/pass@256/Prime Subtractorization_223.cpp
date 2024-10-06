
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
#include <unordered_map>
using namespace std;

void sieve(int N, vector<bool>& is_prime) {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
}

int solve(int N) {
    vector<bool> is_prime(N + 1, true);
    sieve(N, is_prime);

    unordered_map<int, int> diff_count;
    for (int i = 2; i <= N; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i - 1; j >= 2; --j) {
            if (!is_prime[j]) continue;
            int difference = i - j;
            if (difference >= 1)
                diff_count[difference]++;
        }
    }

    return diff_count.size();
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << solve(N) << endl;
    }
    return 0;
}
