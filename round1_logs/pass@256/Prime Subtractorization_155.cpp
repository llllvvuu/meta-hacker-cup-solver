
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
#include <set>
using namespace std;

set<int> subtractorizations;
bool was_computed = false;

void compute_subtractorizations() {
  if (!was_computed) {
    set<int> primes_up_to;
    // Fill primes_up_to with primes <= 10000000 (sieve of eratosthenes or any other means).
    // ...

    for (auto it_p = primes_up_to.begin(); it_p != primes_up_to.end(); it_p++) {
      for (auto it_q = primes_up_to.begin(); it_q != it_p; it_q++) {
        int diff = *it_p - *it_q;
        if (1 <= diff && diff <= 10000000) {
          subtractorizations.insert(diff);  // Store the difference in the subtractorizations set.
        }
      }
    }
    was_computed = true;
  }
}

int main() {
  int T;
  cin >> T;
  
  // Perform precomputation once before handling input.
  compute_subtractorizations();
  
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    cout << "Case #" << t << ": ";
    
    // Count and print the number of subtractorizations up to N.
    cout << subtractorizations.size() <= N ? subtractorizations.size() : 
    *(lower_bound(subtractorizations.begin(), subtractorizations.end(), N) - 1) << endl;
  }
  return 0;
}
