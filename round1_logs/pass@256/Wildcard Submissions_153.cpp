
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
#include <string>
#include <vector>
#include <array>

using namespace std;

const int MOD = 998244353;
char Q  = '?';
int dp[27][1 << 26] = {0};
vector<string> words;

int dfs(int idx, int state, int is_question_mark_present) {
    if (idx == words[0].length()) return is_question_mark_present ? 1 : 0;
    long long &res = dp[idx][state];
    if(res == -1) { 
        res = 0;
        for (int ch = 'A'; ch <= 'Z'; ch++) {
            int new_state = state | (1 << (ch - 'A'));
            res += dfs(idx + 1, new_state, is_question_mark_present || ch == Q);
        }
    }
    return res % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t_case = 1; t_case <= T; t_case++) {
        words.clear();
        int N;
        cin >> N;
        words.reserve(N);
        for (int i = 1; i <= N; i++) {
            string word;
            cin >> word;
            words.push_back(word);
        }

        // Initialize dp array for the first string
        for (int i = 0; i < 26; i++) fill(dp[i], dp[i] + (1 << 26), -1);
        long long total_patterns = dfs(0, 0, Q == words[0][0]);
        
        cout << "Case #" << t_case << ": " << (total_patterns % MOD) << endl;
    }
    return 0;
}
