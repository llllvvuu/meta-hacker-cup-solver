
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
#include <bitset>
#include <iostream>
using namespace std;

int main() {
  int n_cases;
  cin >> n_cases;
  bitset<10000001> not_prime;
  not_prime[0] = not_prime[1] = 1;
  for (int i = 2; i * i <= 10000000; ++i) {
    if (!not_prime[i]) {
      for (int j = i * i; j <= 10000000; j += i) {
        not_prime[j] = 1;
      }
    }
  }

  for (int ii = 1; ii <= n_cases; ++ii) {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 2; i <= N; ++i) {
      if (!not_prime[i]) {  // Check the "i"th number in the array
        for (int j = 2; j <= i; ++j) {
          if (!not_prime[j] && !not_prime[i - j]) {
            if (j != i - j) {
              count++;
            }
          }
        }
      }
    }
    cout << "Case #" << ii << ": " << count / 2 << endl;  // Only consider unique pairs
  }
  return 0;
}
