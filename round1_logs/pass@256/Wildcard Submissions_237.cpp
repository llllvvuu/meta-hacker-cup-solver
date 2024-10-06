
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
#include <set>
#include <string>
using namespace std;

const int p = 998244353;

string s[50];
bool was[103][28];
set<string> a;

int dfs(int i, int j) {
    if(i == s[j].size()) return 1;
    int res = 0;
    if(s[j][i] == '?') {
        for(int k = 0; k < 26; k++) 
            if(!was[i][k] && !a.count(s[j].substr(0, i) + (char)(k + 'A'))){
                a.insert(s[j].substr(0, i) + (char)(k + 'A'));
                was[i][k] = true;
                res += dfs(i+1, j);
                res %= p;
            }
    }
    else {
        if(!a.count(s[j].substr(0, i) + s[j][i]))
            a.insert(s[j].substr(0, i) + s[j][i]);
        res = dfs(i+1, j);
    }
    return res;
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        a.clear();
        cin >> N;
        for(int i = 0; i < N; i++) cin >> s[i];
        int res = dfs(0, 0);
        for (int i = 0; i < N; i++)
            for(int j = 0; j < s[i].size(); j++)
                was[j][s[i][j] - 'A'] = false;
        cout << res << endl;
    }
    return 0;
}
