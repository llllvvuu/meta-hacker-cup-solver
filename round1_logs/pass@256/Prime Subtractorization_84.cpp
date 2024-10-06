
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

const int MAXN = 1e7;

bitset<MAXN+7> nums;
vector<int> primes;

void sieve(int N) {
  nums.set();
  for(int i = 2; i < N + 1; i++) {
      if(nums[i]) {
          primes.push_back(i);
          for(int j = i + i; j < N + 1; j += i) nums[j] = false;
      }
  }
}

int subtractorizations(int N) {
  sieve(N);
  bitset<MAXN+7> diff_counter;
  for(int i = 0; i < primes.size(); i++) {
      for(int j = 0; j < i; j++) {
          if(primes[i] - primes[j] > 0 && primes[i] - primes[j] <= N) {
              diff_counter[primes[i]-primes[j]] = true;
          }
      }
  }
  return diff_counter.count();
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": " << subtractorizations(N) << endl;
    }
    return 0;
}
