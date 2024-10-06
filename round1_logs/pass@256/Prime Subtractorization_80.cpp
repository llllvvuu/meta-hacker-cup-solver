
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
#include <cstring>
using namespace std;

const int N_MAX = 10000009; // +2 for primes generation since 2 <= N <= 10000000  => N + 2 <= 10000002
bool sieve[N_MAX];

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int n;
        cin >> n;
        
        // Initialize sieve
        memset(sieve, true, sizeof(sieve));
        sieve[0] = sieve[1] = false;
        
        // Sieve of Eratosthenes
        for(long long int i = 2; i * i < N_MAX; i++){
            if(sieve[i]){
                for(long long int j = i * i; j < N_MAX; j += i){
                    sieve[j] = false;
                }
            }
        }
        
        // Count number of subtractorizations
        int count = 0;
        for(int i = 2; i <= n + 2; i++){
            if(sieve[i]){
                for(int j = 2; j <= i - 1; j++){
                    if(sieve[i - j]) count++;
                }
            }
        }
        
        cout << "Case #" << t << ": " << count / 2 << endl; // each prime difference is counted twice
    }
    return 0;
}
