
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
using namespace std;

const int MAX_VAL = 10000001;
bool is_prime[MAX_VAL];
int prime[MAX_VAL];
int prime_index = 0;
bool existing[MAX_VAL]; // Possible differences placeholder 

void sieve() {
    fill(is_prime, is_prime + MAX_VAL, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_VAL; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX_VAL; j += i) {
                is_prime[j] = false;
            }
        }
    }
    prime[0] = 2;
    for (int i = 3, idx = 1; i < MAX_VAL; i += 2) { // Start from 3, increment by 2 (primes are odd except 2)
        if (is_prime[i]) {  prime[++prime_index] = i; }
    }
}

int main() {
  sieve();
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    fill(existing, existing + MAX_VAL, false);
    int count = 0;
    
    for (int i = 0; prime[i] <= N; ++i) {
        int a = prime[i]; // the prime minuend
        for (int j = 0; prime[j] <= a && prime[j] <= N; ++j) {
            int b = prime[j]; // the prime subtracting
            int x = a - b;
            if (x <= N && !existing[x]) { 
                existing[x] = true; 
                count++;
            }
        }
    }
    cout << "Case #" << t << ": " << count << "\n";
  }

  return 0;
}
