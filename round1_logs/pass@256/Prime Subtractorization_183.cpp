
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

bool is_prime(int n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

int solution(int N) {
  if (N == 2) return 1;
  int count = 0;

  // count 2 if N is odd or if N-2 is prime.
  if (N % 2 == 1 || is_prime(N - 2)) count += 1;

  // If N itself is prime, it can be subtracted from any larger prime (up to N).
  // Hence, it counts as an *$N$-subtractorization*.
  if (is_prime(N)) count += 1;

  return count;
}

void solve_test_cases(int T) {
  for (int i = 1; i <= T; i++) {
    int N;
    std::cin >> N;
    std::cout << "Case #" << i << ": " << solution(N) << "\n";
  }
}

int main() {
  int T;
  std::cin >> T;
  solve_test_cases(T);
  return 0;
}
