
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
  cin.tie(0)->sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<int> is_prime(N + 1, 1);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
          if (is_prime[i]) {
              for (int j = i * i; j <= N; j += i) {
                  is_prime[j] = false;
              }
          }
      }

    int count = 0;
    if (N > 2 && is_prime[N - 2]) {
      count++;
    }
    if (N > 3 && N % 2 == 0 && is_prime[N - 3]) {
      count++;
    }
    if (N > 5 && N % 2 == 0 && is_prime[N - 5]) {
      count++;
    }
 
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
