
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
using namespace std;
const int M = 998244353;

int T[300][30]; // Max depth = 101, 26 letters

void dfs(const string& s, int i, int path, vector<vector<long long>>& unique_paths) {
    if (i == s.size()) {
        unique_paths[i][path]++;
        return;
    }
    T[min(i + 1, 101)][path]++;
    if (s[i] == '?') {
        for (int j = 0; j < 26; j++) // (dfs(s, i + 1, path * 26 + j, unique_paths));
            dfs(s, i + 1, path * 26 + j, unique_paths);
    } else {
        dfs(s, i + 1, path * 26 + s[i] - 'A', unique_paths);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    memset(T, 0, sizeof(T));
    int T, N;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        cin >> N;
        vector<vector<long long>> unique_paths(101, vector<long long>(3e5 + 10, 0));
        for (int i = 0; i < N; i++) { 
            string s; cin >> s;
            dfs(s, 0, 0, unique_paths);
        }
        long long res = 0;
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j < (int)unique_paths[i].size(); j++)
                if (unique_paths[i][j] != 0) {
                    res = (res + T[i][j]) % M;
                }
        cout << "Case #" << cas << ": " << res << "\n";
    }
    return 0;
}
