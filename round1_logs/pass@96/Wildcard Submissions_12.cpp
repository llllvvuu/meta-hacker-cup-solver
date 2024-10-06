
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

bool explore(string &str, int i, map<string, bool> &paths) {
    if (i == str.length()) return true;
    if (str[i] == '?') {
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            str[i] = ch;
            if (explore(str, i + 1, paths)) return true;
        }
        str[i] = '?';
        return false;
    } else {
        string p = str.substr(0, i + 1);
        if (!paths[p]) paths[p] = true;
        return explore(str, i + 1, paths);
    }
    return false;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    map<string, bool> paths;
    for (int i = 0; i < N; i++) {
      string S;
      cin >> S;
      explore(S, 0, paths);
    }
    cout << (paths.size() - 1) % MOD << endl; // minus one for the empty string
  }
  return 0;
}
