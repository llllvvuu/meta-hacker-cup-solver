
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
const int MAX_N = 10000001; // Handle the maximum N value

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  std::vector<bool> isPrime(MAX_N + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int p = 2; p * p <= MAX_N; p++) {
    if (isPrime[p]) {
      for (int i = p * p; i <= MAX_N; i += p)
        isPrime[i] = false;
    }
  }

  std::vector<int> primes;
  for (int i = 2; i <= MAX_N; i++) {
    if (isPrime[i]) primes.push_back(i);
  }

  int T;
  std::cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    std::cin >> N;

    std::bitset<MAX_N> subtractorizations;
    for (int p : primes) {
      if (p > N) break;
      for (int q : primes) {
        if (q > p) break;
        int diff = p - q;
        if (diff <= 0 || diff > N) break;
        if (isPrime[diff]) subtractorizations[diff] = true;
      }
    }

    long result = subtractorizations.count();
    std::cout << "Case #" << t << ": " << result << std::endl;
  }
  return 0;
}
