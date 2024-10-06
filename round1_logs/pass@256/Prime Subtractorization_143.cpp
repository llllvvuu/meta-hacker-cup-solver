
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
using namespace std;

bool sieve[10000005]; // for prime checking

vector<int> generate_primes(int N) {
    fill(sieve, sieve + N + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= N; j += i) {
                sieve[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int count_subtractorizations(int N) {
    vector<int> primes = generate_primes(N);
    int count = 0;
    int sz = primes.size();
    for (int i = 0; i < sz; i++) {
        for (int j = i; j < sz; j++) {
            int diff = primes[j] - primes[i];
            if (diff <= N && sieve[diff]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << count_subtractorizations(N) << endl;
    }
    return 0;
}
