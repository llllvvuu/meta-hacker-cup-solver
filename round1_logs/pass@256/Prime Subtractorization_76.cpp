
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
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime[10000001];

void sieve(int N) {
    fill(isPrime, isPrime + N + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        sieve(N);
        int primeDiffCount = (N > 2);
        vector<int> primes;
        for (int i = 2; i <= N; i++) {
            if (isPrime[i]) {
                primeDiffCount += isPrime[N - i] && N - i > 1;
                if (N - i > 1) primes.push_back(N - i);
            }
        }
        if (primeDiffCount > 1) {
            primeDiffCount++;
        }
        cout << primeDiffCount << endl;
    }
    return 0;
}
