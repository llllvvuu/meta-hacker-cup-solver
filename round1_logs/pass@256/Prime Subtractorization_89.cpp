
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

int isPrime(int n) {
    if (n <= 1) return 0; // Not a prime.
    if (n == 2) return 1; // 2 is a prime.
    if (n % 2 == 0) return 0; // Even numbers greater than 2 are not primes.
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    
    for(int case_idx = 1; case_idx <= T; case_idx++) {
        int N;
        cin >> N;
        int count = 0;
        
        // Count odd primes <= N
        if (N == 2) count += 1; // Only count 2 if N is exactly 2.
        for(int i = 3; i <= N; i += 2) {
            if(isPrime(i)) count++;
        }
        
        cout << "Case #" << case_idx << ": " << count << "\n";
    }
    
    return 0;
}
