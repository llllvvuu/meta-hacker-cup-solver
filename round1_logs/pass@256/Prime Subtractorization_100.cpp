
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

int main() {
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    int N;
    cin >> N;
    int cases = i;
    cout << "Case #" << cases << ": ";

    vector<int> is_prime(N * 2 + 1, true);
    is_prime[0] = is_prime[1] = false;

    int count = 0;
    for (int p = 2; p <= N * 2; p++) {
      if (is_prime[p]) {
        count++;
        if (p > N) 
          break;
        for (int j = p * 2; j <= N * 2; j += p)
          is_prime[j] = false;
      }
    }
    if (count > 0) 
      count--;  // The case for 2 needs special consideration as it cannot be expressed as p-2 where p is prime.

    cout << count << "\n";
  }
  return 0;
}
