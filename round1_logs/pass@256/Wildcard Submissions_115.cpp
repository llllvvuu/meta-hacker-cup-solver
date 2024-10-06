
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
using namespace std;

const int MOD = 998244353;
struct Answer {
  unsigned long long add, carry;

  bool operator<(const Answer& rhs) const {
    return carry != rhs.carry ? carry < rhs.carry : add < rhs.add;
  }
};

Answer operator+(Answer a, Answer b) {
  a.add = (a.add + b.add) % MOD;
  a.carry = (a.carry + b.carry) % MOD;
  return a;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    string S[N];
    for (int i = 0; i < N; i++)
      cin >> S[i];

    Answer ans;
    for (int i = 0; i < N; i++) {
      bool wildcard = false;
      unsigned long long add = 0;
      for (char c : S[i]) {
        if (c == '?')
          wildcard = true;
        else {
          add = (add + wildcard * 26) % MOD;
          wildcard = true;
        }
      }
      ans = ans + Answer{add + 1, 26 + wildcard};
    }

    cout << "Case #" << t << ": " << ans.add << endl;
  }
  return 0;
}
