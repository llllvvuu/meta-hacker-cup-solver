
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
#include <array>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

constexpr size_t BSIZE = 1 << 16;

void sieve(vector<bool>& primes, bitset<BSIZE>& sp, size_t N) {
  primes.resize(N + 1);
  primes[0] = primes[1] = false;
  for (size_t i = 2; i <= N; i++) {
    primes[i] = true;
    if (!primes[i]) continue;
    sp.reset();
    for (size_t j = i * i; j <= N; j += i) primes[j] = false;
    if (i > BSIZE) continue;
    for (size_t j = i * i; j <= N; j += i) sp[j % BSIZE] = false;
  }
}

bitset<BSIZE> subtractorizations(size_t N, const vector<bool>& primes) {
  bitset<BSIZE> res;
  for (size_t i = 2; i <= N; i++) {
    if (!primes[i]) continue;
    bitset<BSIZE> sp;
    for (size_t j = 2; i * j <= N; j++) sp[i * j % BSIZE] = false;
    for (size_t j = 0; j <= N; j++) {
      if (!sp[j % BSIZE] && (j < 2 || !primes[j]) && i - j > 1 && i != j)
        res[i - j] = true;
    }
  }
  return res;
}

bitset<BSIZE> subtractorizations(size_t N) {
  bitset<BSIZE> res;
  vector<bool> primes;
  bitset<BSIZE> sp;
  for (size_t i = 0; i < (N + BSIZE - 1) / BSIZE; i++) {
    size_t lo = i * BSIZE;
    size_t hi = min(N, (i + 1) * BSIZE - 1);
    sieve(primes, sp, hi);
    res |= subtractorizations(hi, primes) << lo;
    for (size_t i = lo; i <= hi; i++) {
      primes[i] = primes[i % BSIZE];
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    size_t N;
    cin >> N;
    auto res = subtractorizations(N);
    cout << "Case #" << t << ": " << res.count() << endl;
  }
  return 0;
}
