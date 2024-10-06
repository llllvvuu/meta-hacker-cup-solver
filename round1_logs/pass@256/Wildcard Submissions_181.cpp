
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
#include <cstring>
#include <string>
using namespace std;

vector<int> tries[101][26];
int mod = 998244353;

int calculate(int depth, string wild) {
    if (depth >= wild.size()) return 1;
    if (wild[depth] == '?') {
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + calculate(depth + 1, wild)) % mod;
            ans = (ans + tries[depth][i].back()) % mod;
        }
        tries[depth][wild[depth] - 'A'].push_back(ans);
        return ans;
    } else {
        tries[depth][wild[depth] - 'A'].push_back(calculate(depth + 1, wild));
        return tries[depth][wild[depth] - 'A'].back();
    }
}

int solve() {
    int N;
    cin >> N;
    vector<string> wildcard_strings(N);
    for (int i = 0; i < N; i++) {
        cin >> wildcard_strings[i];
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        memset(tries, 0, sizeof tries);
        answer = (answer + calculate(0, wildcard_strings[i])) % mod;
    }
    return (answer + mod - 1) % mod; // Adjust for the root node being counted once extra
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
