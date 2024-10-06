
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
#include <bitset>
#include <iostream>
using namespace std;
const int MOD = 998244353;

bitset<101> prefix_compute(const string &S, int L) {
  bitset<101> mask(false);
  for (int i = 0; i < L; i++)
    mask[i] = ((S[i] ^ '?') && (S[L - 1 + i - L] ^ '?'));
  return mask;
}

int strings_in_roi(const string &S, int i, int j) {
  const bitset<101> allones = bitset<101>(-1);
  bitset<101> B = allones;
  for (int k = i; k < j; ++k) {
    B &= prefix_compute(S, k - i + 1);
  }
  return B.count();
}

int parse_string(const string &S) {
  int count = 0;
  int L = S.size();
  for (int L = 1; L <= S.size(); ++L) {
    count = (count + 1L * strings_in_roi(S, 0, L) * (L - strings_in_roi(S, 0, L) + 1)) % MOD;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    string s[N];
    long long result = 0;
    for (int i = 0; i < N; ++i) cin >> s[i], result += parse_string(s[i]);
    result %= MOD;
    cout << "Case #" << t << ": " << result << "\n";
  }
  return 0;
}
