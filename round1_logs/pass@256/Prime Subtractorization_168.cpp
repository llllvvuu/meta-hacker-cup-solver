
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
#include <bitset>
using namespace std;

bitset<10000001> is_prime; // Bitset to mark primes

void generate_primes(int N) {
    is_prime.set();
    is_prime[0] = 0; is_prime[1] = 0;
    for(int i = 2; i * i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i*i; j <= N; j += i) is_prime[j] = 0;
        }
    }
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        generate_primes(N); // Generate primes up to N
        vector<int> primes; // List of primes up to N
        for(int i = 2; i <= N; i++) if(is_prime[i]) primes.push_back(i);
        int answer = 0;
        for(auto& p : primes) {
            bool found = false;
            // Check for N-subtractorization conditions
            for(auto& q : primes) {
                if(q >= p) break;
                int diff = p - q;
                if(diff > 1 && diff <= N && is_prime[diff]) {
                    found = true;
                    break; // found one, don't need more
                }
            }
            if(found) answer++;
        }
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}
