
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

bool is_prime(int n) {
    vector<bool> primes(n+1, true);
    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= n; i++) {
        if(primes[i]) {
            for(int j = i; i * j <= n; j++) {
                primes[i*j] = false;
            }
        }
    }
    return primes[n];
}

int main() {
  int T;
  cin >> T;
  
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    
    int count = 0;
    // Count the number of primes less or equal to N that can be expressed as N - prime
    for(int i = 2; i <= N; i++) {
      if(i >= 2 && is_prime(i) && is_prime(N - i)) {
        count++;
      }
    }
    
    cout << "Case #" << t + 1 << ": " << count << endl;
  }
  return 0;
}
