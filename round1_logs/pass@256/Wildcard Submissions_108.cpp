
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
#include <map>
using namespace std;

const int MOD = 998244353;
map<string, int> m;

bool addPair(string &w, int start, int end) {
    if (start == end && w[start] == '?') {
        for (char i = 'A'; i <= 'Z'; i++)
            m[w.substr(0, start) + i]++;
    }
    if (start == end)
        return true;
    for (char i = 'A'; i <= 'Z'; i++)
        if (w[start] == '?' || w[start] == i)
            if (addPair(w, start+1, end))
                m[w.substr(0, start) + i]++;
    return false;
}

void addString(const string& s) {
  int n = s.size();
  addPair(s, 0, n);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    m.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      addString(s);
    }
    long long total = 0;
    for (auto x : m)
        total = (total + x.second) % MOD;
    cout << "Case #" << t << ": " << total << endl;
  }
  return 0;
}
