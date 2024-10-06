
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
#include <iostream>
#include <vector>
using namespace std;

const int p = 998{,}244{,}353;
vector<int> pref;

int mod_expo(int b, int p) {
  int r = 1;
  while (p) {
    if (p & 1) r = (long long)r * b % p;
    b = (long long)b * b % p;
    p >>= 1;
  }
  return r;
}

pair<vector<int>, vector<int>> process(string s) {
  int n = (int)s.size();
  vector<int> a(n + 1), b(n + 1);
  for (int i = 0; i < n; i++) {
    a[i + 1] = a[i] + (!isupper(s[i]));
    b[i + 1] = b[i] * 26 + (s[i] == '?')
      ? 1
      : (s[i] - 'A' + 1);
  }
  return {a, b};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    pref.clear();
    pref.reserve(200'000); //more than enough
    for (int i = 0; i < N; i++) {
      string s;
      cin >> s;
      vector<int> a, b;
      tie(a, b) = process(s);
      prefix.pb(make_pair(
        mod_expo(31, a[n]), b[n] // each unique pattern is (a, b)
      ));
    }
    sort(pref.begin(), pref.end());
    pref.erase(unique(pref.begin(), pref.end()), pref.end());
    cout << pref.size();

  }
  return 0;
}
