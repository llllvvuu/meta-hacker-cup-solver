
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
using namespace std;
const int mod = 998244353;

pair<int, int> first, second;
int total_patterns;
int taken[105] = {}; // indexes of chars to skip

int calculate(int state, int step, vector<string> &strings) {
    if (step == strings.size()) return 1;
    if (first.first * second.first * step == state) return 0;

    int &ans = taken[state];
    if (!taken[state]) {
        ans = 0;
        for (int k = 0; k < strings[step].size(); k++) {
            if (taken[state << 26] && strings[step][k] != first.second) continue;
            auto next_state = (state << 26) + ((strings[step][k] == '?') ? 0 : strings[step][k] - 'A' + 1);
            ans += calculate(next_state, step + 1, strings);
            if (ans >= mod) ans -= mod; 
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    vector<string> strings;
    for (int tc = 1; tc <= T; tc++) {
        first = second = {{1, 0}, {0, 0}};
        memset(taken, 0, sizeof(taken));
        cin >> total_patterns;
        strings.resize(total_patterns);
        for (auto &s: strings) cin >> s;    
        cout << "Case #" << tc << ": " << total_patterns * (state = 0) + calculate(state, 0, strings) << endl;
    }
    return 0;
}
