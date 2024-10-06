
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
#include <unordered_set>
using namespace std;

bool is_prime[10000001];
vector<int> primes;

void sieve(int N) {
    for (int i = 2; i <= N; i++) is_prime[i] = true;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) 
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
    }
    for (int i = 2; i <= N; i++)
        if (is_prime[i]) primes.push_back(i);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    sieve(N);
    
    unordered_set<int> subtractorizations;
    for (int i = 0; i < primes.size(); ++i) {
      for (int j = i + 1; j < primes.size(); ++j) {
        int diff = primes[j] - primes[i];
        if (diff > N) break;
        subtractorizations.insert(diff);
      }
    }
    
    cout << "Case #" << t << ": " << subtractorizations.size() << endl;
    primes.clear();
  }
  return 0;
}
