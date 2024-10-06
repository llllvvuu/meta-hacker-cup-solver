
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

long long p[2000000];
long long weights[2000005];
long long dp[2000005];
int sz;

long long ComputeInverse(long long a, long long m) {
  long long x, y;
  // Extended Euclidean Algorithm to find a^-1
  return a * x + m * y == 1 ? x : m + x; // return (x % m + m) % m;
}

long long NumOfChoices(long long n, long long k) {
  long long answer = (p[n-k] * p[k]) % 998244353;
  return (answer * p[n]) % 998244353;
}

long long expect(long long t) {
  long long answer = -1;
  if (t >= sz) return 0;
  if (dp[t] != -1) return dp[t];
  if (weights[t+1] == W || weights[t+1] == G) {
    answer = 1;
  } else if (weights[t+1] > W || weights[t+1] < G) {
    answer = NumOfChoices(t+1, t);
  } else {
    answer = (NumOfChoices(t+1, t) * expect(t+1)) % 998244353;
    answer = (answer + expect(t+1)) % 998244353;
  }
  dp[t] = answer;
  return answer;
}

long long Solve() {
  long long inv2 = ComputeInverse(2, 998244353);
  cin >> W >> G >> L;
  sz = (L+1) * 2 + max(L+1, G-W+2);
  long long diff = W - G;
  if (W + L <= G) return diff;
  for (int i = 0; i < sz; i++) {
    if (i <= L) weights[i] = W-i;
    else if (i <= L+G-W+1) weights[i] = G;
    else weights[i] = G + i - (L+G-W+2);
  }
  for (int i = 0; i < sz; i++) dp[i] = -1;
  long long answer = expect(0);
  answer = (answer * inv2) % 998244353;
  return answer;
}
 
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  p[0] = 1;
  for (int i = 1; i < 2000000; i++) p[i] = (p[i-1] * i) % 998244353;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << Solve() << endl;
  }
}
