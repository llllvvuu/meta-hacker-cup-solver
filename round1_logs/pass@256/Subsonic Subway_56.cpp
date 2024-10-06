
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

typedef vector<pair<pair<int,int>, int>> vp;

double solve(int N, vector<vp> times) {
  vp sep;
  vp cur = {{-1, -1}, -1};

  for (int i = 0, m = times.size(); i < m; i++) {
    int a = times[i].first.first;
    int b = times[i].first.second;
    int d = times[i].second;
    
    if (cur.second + d <= a) { // initial or noninterference
      if (sep.empty() || sep.back().second + 1e-6 - d >= rmin(b, max(d, rmax(sep.back().first.first, sep.back().first.second))))
        sep.push_back({{b, rmax(sep.empty() ? -1e9: sep.back().first.second, min(d, a))}, d});
    } else
      cur.first.second = max(cur.first.second, b);
  }

  if (sep.empty() || sep.back().first.second + 1e-6 > sep.back().second)
    return -1;

  double ans = sep.empty() ? cur.first.second+1e-6-cur.second : sep.back().first.second-1e-6+sep.back().second;
  for (auto& t : sep) ans = min(ans, double(t.first.second-t.second)/t.second);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    
    vector<pair<pair<int,int>,int>> V;
    for (int j = 0; j < N; j++) {
      int a, b;
      cin >> a >> b;
      V.push_back({{a,b},j+1});
    }

    cout << "Case #" << t << ": " << solve(N,V) << '\n';
  }
  return 0;
}
