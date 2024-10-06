
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

const int MOD = 998244353;

void add(int& x, int y) {
    x = (x + y) % MOD;
}

int solve(string s) {
    vector<long long> rem(s.size() + 1);
    vector<int> last(26, -1);

    int ans = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != '?') {
            add(ans, last[s[i] - 'A'] ? (26 - last[s[i] - 'A']) * rem[i + 1] : 26 * rem[i + 1]);
            last[s[i] - 'A'] = 1;
        } else {
            add(ans, (26 - (int)count(last.begin(), last.end(), 1)) * rem[i + 1]);
        }
        for (int j = 0; j < 26; j++)
            add(rem[i], rem[i + 1]);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int N;
        cin >> N;

        vector<string> S(N);
        for (int i = 0; i < N; i++)
            cin >> S[i];

        long long total = 0;
        for (auto&& s : S)
            add(total, solve(s));
        
        cout << "Case #" << testcase << ": " << total << "\n";
    }
    return 0;
}
