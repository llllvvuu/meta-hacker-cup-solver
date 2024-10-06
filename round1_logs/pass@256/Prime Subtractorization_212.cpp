
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

const int MAX_N = 10000000;

bool prime[MAX_N+1];

bool is_prime(long num) {
  if(num == 2) return true;
  if(num % 2 == 0) return false;
  for(long i = 3; i * i <= num; i += 2)
     if(num % i == 0) return false;
  return true;
}

void sieve(int n) {
  for(int i = 2; i <= n; i++)
    prime[i] = true;
  for(int i = 2; i * i <= n; i++) {
    if(prime[i]) {
      for(int j = i * i; j <= n; j += i) 
        prime[j] = false;
    }
  }
}

int solve(int n) {
  vector<int> diff;
  sieve(n);
  for(int i = 2; i <= n; i++)
    if(prime[i])  // i is a prime number
      for(int j = i; j <= n and j >= i - n + 1; j++) 
        if(prime[j] and is_prime(j - i)) diff.push_back(j - i);
  return diff.size();
}

int main() {
  int t;
  cin >> t;
  vector<int> ans(t);
  for(int i = 0; i < t; i++) {
    int n;
    cin >> n;
    ans[i] = solve(n);
  }
  for(int i = 0; i < t; i++) cout << "Case #" << i + 1 << ": " << ans[i] << endl;
  return 0;
}
