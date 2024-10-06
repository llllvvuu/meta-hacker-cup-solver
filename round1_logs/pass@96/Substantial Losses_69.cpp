
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
#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

int mpow(int a, int b){
  int res = 1;
  while(b){
    if(b&1) res = res * 1ll * a % mod;
    b >>= 1; a = a * 1ll * a % mod;
  }
  return res;
}

map<pair<int, int>, long long> dp;

int solve(int a, int b, int l) {
  if(dp.count({a, b})) return dp[{a, b}];
  if(a == b) return 0;
  if(a - b > l) return 1 + (solve(a - 1, b, l) + solve(a + 1, b, l)) % mod;
  int ans = 0;
  if(b == l) {
    ans = mpow(2, a - b);
  } else {
    ans = (solve(a + 1, b, l) + solve(a - 1, b - 1, l)) % mod;
  }
  return dp[{a, b}] = ans;
}

int main() {
  int T, a, b, l;
  cin >> T;
  while(T--) {
    cin >> a >> b >> l;
    printf("Case #%d: ", T + 1);
    if(a - b <= l) {
      cout << solve(a, b, l) * mpow(2, mod - 2) % mod << "\n";
    } else {
      cout << (a - b) % mod << "\n";
    }
  }
  return 0;
}
