
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
#include <cstdint>
#include <iostream>
#include <vector>

const uint_fast64_t MOD = 998244353;

uint_fast64_t exp(uint_fast64_t b, uint_fast64_t e) {
  uint_fast64_t r(1);
  for(; e; b = b*b%MOD, e /= 2) if (e&1) r = r*b%MOD;
  return r;
}

uint_fast64_t inv(uint_fast64_t n) {
  return exp(n, MOD - 2);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; t++) {
    uint64_t W, G, L;
    std::cin >> W >> G >> L;
    std::cout << "Case #" << t << ": ";
    
    if (W - G > L) {
        std::cout << (W - G) % MOD << '\n';
        continue;
    }
    
    std::vector<uint_fast64_t> f(W - G + 1);
    for (uint_fast64_t w = W - G; w >= G; w--) {
        if (w < L)
            f[w] = (1 + (f[w + 1] + f[w + 2] - f[w + 1 + L]) * inv(2)) % MOD;
        else {
            uint_fast64_t nxt = std::min(w + 2, G);
            f[w] = (1 + (f[w + 1] + f[nxt] - f[w + 1]) * inv(2)) % MOD;
        }
    }
    std::cout << f[G] << '\n';
  }
  return 0;
}
