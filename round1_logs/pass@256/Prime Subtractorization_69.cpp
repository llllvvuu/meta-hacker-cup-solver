
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
#define MAXN 10000001
vector<int> primes;
bitset<MAXN> is_prime;
vector<bool> has_prime_diffs;

#define memset(set, value) set.reset(); set.flip(); set.flip();
#define clear(set) set.reset();

void sieve() {
    is_prime.reset();
    is_prime.flip();
    is_prime.flip();
    for (int i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
