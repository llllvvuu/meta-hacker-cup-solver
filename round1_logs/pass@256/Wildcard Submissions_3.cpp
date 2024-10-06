
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
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

const int MOD = 998244353;
using LL = unsigned long long;

map<string, map<string, LL> > dp;

LL countPrefix(string& s, int idx) {
    if (idx == s.size()) return 1;
    auto updates = set<string>();
    LL subtotals[2] = {0};
    for (int i = idx; i < s.size(); ++i) {
        auto& cm = dp[dp.is...]
}
