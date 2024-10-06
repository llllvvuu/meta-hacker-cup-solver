
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
int C;

bool primes[10000001];

bool is_prime(int n){
    for(int f = 2; f*f <= N; f++)
        if (!(n%f)) return false;
    return true;
}

// Sieve of Eratosthenes
void sieve(int n){
    for(int i = 0; i <= n; ++i)
        primes[i] = true;
    primes[0] = primes[1] = false;
    for(int i = 2; i <= n; ++i)
        if(primes[i]) 
            for(int j = i*i; j <= n; j+=i)
                primes[j] = false;
}

int main() {
    cin >> T;
    vector<int> results;
    for(int t = 1; t <= T; t++){
        cin >> N;
        sieve(N);
        C = 1;  // 2 is the only even subtractorization
        for(int i = 3; i <= N; i += 2) {
            if (is_prime(i)){
                for(int j = 2; j <= N; j++) {
                    if (primes[j] && primes[i - j] && i - j <= N)
                        C++;
                }
            }
        }
        cout << "Case #" << t << ": " << C << endl;
        results.push_back(C);
    }
    return 0;
}
