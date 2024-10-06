
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e7 + 5;
bool is_prime[MAXN];

void sieve(int N) {
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int countSubtractorizations(int N) {
  sieve(N);
  int count = 0;
  if (N >= 3)
    count++;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i] && is_prime[N - i]) {
      count++;
    }
  }
  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    int result = countSubtractorizations(N);
    cout << "Case #" << t << ": " << result << endl;
  }

  return 0;
}
