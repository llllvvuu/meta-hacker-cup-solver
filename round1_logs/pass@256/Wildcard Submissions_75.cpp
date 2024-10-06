
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
#include <assert.h>
#include <cinttypes>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 998244353;
constexpr int MAXLEN = 100;
constexpr int MAXSTRS = 35;
constexpr int LETTERS = 26;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int TC;
  cin >> TC;
  assert(1 <= TC && TC <= 105);
  
  char buffer[MAXLEN+1];
  vector<vector<int>> counts(MAXLEN+1, vector<int>(LETTERS+1, 0));
  for (int caseid = 1; caseid <= TC; caseid++) {
    const int N; cin >> N;
    assert(1 <= N && N <= MAXSTRS);
    counts.assign(MAXLEN+1, vector<int>(LETTERS+1, 0));

    for (int st = 0; st < N; st++) {
      const int len; cin >> setw(len = MAXLEN) >> buffer;
      assert(!buffer[len]);
      for (int depth = 0; depth < len; depth++) {
        ++counts[depth][buffer[depth] == '?' ? LETTERS : buffer[ depth ] - 'A'];
      }
    }

    int64_t node_count = 0;
    for (int depth = 0; depth <= MAXLEN; depth++) {
      const int64_t mult = 1;
      int64_t lime = 0;

      for (int ch = 0; ch <= LETTERS; ch++) {
        int64_t tmp = mult * counts[depth][ch] - lime;
        if (tmp < 0) tmp += MOD;
        lime += tmp;
        if (lime >= MOD) lime -= MOD;
      }
      node_count += lime;
      if (node_count >= MOD) node_count -= MOD;
    }

    cout << "Case #" << caseid << ": " << node_count << endl;
  }

  return 0;
}
