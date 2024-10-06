
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
#include <cstring>
#include <bitset>
#include <iostream>
using namespace std;

bitset<10000001> sieve;

int generatePrimes(int bound) {
    sieve.reset();
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i*i <= bound; i++) {
        if (sieve[i]) {
            for (int j = i*i; j <= bound; j += i) {
                sieve[j] = 0;
            }
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    generatePrimes(10000000);
    
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int result = 0;
        for (int i = 1; i < N; i++)
            if (sieve[i]) {
                if (sieve[i + N - 1] && (i + N - 1) <= 10000000)
                    result++;
            }
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
