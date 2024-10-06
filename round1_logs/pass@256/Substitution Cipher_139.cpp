
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
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<ll, string> fker;

const int MOD = 998244353, MAXN = 100005;

ll dp[MAXN];
ll memo[MAXN];
int last_processed[MAXN];
vector<int> digits;
const int choose[2][4] = {{1, 10, 100, 1000}, {1, 11, 21, 121}};

bool is_valid(int start, int end) {
  // validation of digit sequence
}
void update_dfk(long long& curr, const int new_val) {
  // update DP table
}
bool DFS(int start, int end) {
  // Depth-first search to compute the best
}
string generate_org_string(const string & curr_string, 
                           const vector<int> & curr_digits, const int k) {
  // generate the lexicographic string
}
int main() {
  // read in input
}
