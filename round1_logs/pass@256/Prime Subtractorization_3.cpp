
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

int T;
int N;
bool isPrime[10000003];

// Sieve of Eratosthenes
void sieve(int N) {
    fill(&isPrime[2], &isPrime[N + 1], true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p)    isPrime[i] = false;
        }
    }
}

int findSubtractorizations(int N) {
    sieve(N);
    int cnt = 0;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = 2; j + i <= N; ++j) {
                if (isPrime[j] && isPrime[j + i]) {
                    cnt++;
                    break; // Only one dif is required for i
                }
            }
        }
    }
    return cnt;
}

int main() {
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> N;
        cout << "Case #" << i << ": " << findSubtractorizations(N) << endl;
    }
    return 0;
}
