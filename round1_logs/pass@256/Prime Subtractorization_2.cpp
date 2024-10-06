
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
#include <cmath>
using namespace std;

bool sieve[10000001];
vector<int> primes;
 
void prepare_sieve(int max){
    fill(sieve, sieve + max + 1, true);
    sieve[0] = false; sieve[1] = false; 
    for(int i = 2; i*i <= max; ++i) {
        if(sieve[i] == true){
            for(int j = i*i; j <= max; j += i) {
                sieve[j] = false;
            }
        }
    }
    for(int i = 0; i < max+1; ++i) {
        if(sieve[i] == true) primes.push_back(i);
    }
}

int subtractorize(int n) {
    prepare_sieve(n); 
    int result = 0;
    for (int i = 0; primes[i] < n; ++i) {
        for (int j = 0; primes[i] - primes[j] >= 2; ++j) {
            if (primes[i] - primes[j] < n && sieve[primes[i] - primes[j]]) 
                ++result;
            // Check if prime in range (0, n]. To avoid double counting
            if (primes[j] - primes[i] < n && sieve[primes[j] - primes[i]])
                ++result;
        }
    }
    return result;
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        cout << "Case #" << t << ": " << subtractorize(N) << endl;
    }
    return 0;
}
