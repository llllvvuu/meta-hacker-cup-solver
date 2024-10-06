
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
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<long long> counts[1001000]; // Holds counters per length for each prefix.
vector<long long> centers(95); // Holds final counts for nodes.

void inc(string p, int length) {
  if (length > p.size()) return;
  for (char x = 'A'; x <= 'Z'; x++) {
    counts[p+x].back() += counts[p].back();
  }
  if (length == p.size() && length > 0) {
    centers[length]++;
  }
  counts[p].push_back(0); // signifies end of chain
}

void counterBuilder(string s) {
  int sz = s.size();
  for (int p = 1; p <= sz; p++) {
    inc(s.substr(0, p), p-1); // Inc occurs for each prefix of s at length p
  }
}

string getPrefix(char x, string ba) { // Rewrites in string format
  if (ba.size() == 0) return string(1,x);
  return string(1,x) + ba;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      centers.assign(95, 0);
      string S;
      cin >> S;
      for (char x = 'A'; x <= 'Z'; x++) {
        counterBuilder(getPrefix(x, S));
      }
    }
    long long sum = centers[0]; // Can never be 0, always at least 1 node.
    for (int i = 1; i <= 100; i++) {
      sum += centers[i] * i;
      sum %= 998244353;
    }
    cout << "Case #" << t << ": " << sum << endl;
  }
  return 0;
}
