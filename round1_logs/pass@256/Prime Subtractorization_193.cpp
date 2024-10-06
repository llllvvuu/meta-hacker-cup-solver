
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
#include <unordered_set>
using namespace std;

bool is_prime[10000001];
int N;
void generate_primes() {
    fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        unordered_set<int> answers;

        generate_primes();

        for (int i = 2; i <= N; ++i) {
            if (!is_prime[i]) {
                continue;
            }
            for (int x = 2; x < i; ++x) {
                if (!is_prime[x]) {
                    continue;
                }
                int diff = i - x;
                if (is_prime[diff] && diff > 1 && answers.find(diff) == answers.end()) {
                    answers.insert(diff);
                }
            }
        }
        cout << "Case #" << t << ": " << answers.size() << endl;
    }
    return 0;
}
