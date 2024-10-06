
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
#include <unordered_set>
using namespace std;

int sieve(int N) {
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
    return prime;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<bool> prime = sieve(N);

        unordered_set<int> subtractorizations;
        for (int i = 2; i * i <= N; i++) {
            if (prime[i]) {
                for (int j = i; j <= N; j += i) {
                    for (int k = j + 1; prime[k] && k <= N; k++) {
                        int diff = k - j;
                        if (prime[diff] && diff <= N) {
                            subtractorizations.insert(diff);
                        }
                    }
                }
            }
        }

        cout << "Case #" << t << ": " << subtractorizations.size() << endl;
    }
    return 0;
}
