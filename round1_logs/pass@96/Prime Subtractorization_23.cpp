
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
using namespace std;

const int MAXN = 10000005;

bool is_prime[MAXN];
vector<int> primes;

void sieve() {
   fill(is_prime, is_prime + MAXN, true);
   is_prime[0] = is_prime[1] = false;
   for (int p = 2; p * p < MAXN; ++p)
      if (is_prime[p])
         for (int i = p * p; i < MAXN; i += p)
            is_prime[i] = false;
   for (int i = 2; i < MAXN; ++i)
      if (is_prime[i])
         primes.push_back(i);
}

int subtractorizations(int N) {
   vector<int> differences;
   for (int p : primes)
      if (p <= N) {
         for (int q : primes) {
            if (p > q && p - q <= N && is_prime[p - q])
               differences.push_back(p - q);
            }
      }
   int cnt[MIN(N, 5000001)];
   fill(cnt, cnt + MIN(N, 5000001), 0);
   for (int diff : differences)
      cnt[diff]++;

   int total = 0;
   for (int i = 1; i <= N; ++i) //iterate up to N
      if (is_prime[i] && cnt[i] > 0)
         ++total;
   return total;
}

int main() {
   int T;
   cin >> T;
   sieve();
   for (int t = 1; t <= T; ++t) {
      int N;
      cin >> N;
      cout << "Case #" << t << ": " << subtractorizations(N) << endl;
   }
   return 0;
}
