
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
#include <set>
using namespace std;
const long long MOD = 998244353;
int N;
vector<string> S;

long long dfs(const string& s, int i) {
    static set<string> myset;
    long long newnodes = 0;
    string prefix;
    for (int j = s.size() - 1; j >= i; j--) { // Loop through string backwards
        prefix = s[j] + prefix;               // Append current character to prefix
        if (myset.count(prefix) == 0) {       // If prefix hasn't been added already
            myset.insert(prefix);             // Add prefix to set
            newnodes += 1;                    // Increment number of new nodes 
        }
        if (s[j] == '?') {                    // If current char is a '?'
            for (char c = 'A'; c <= 'Z'; c++) // Consider all 26 char branches
                newnodes += dfs(s, j + 1);    // Update nodes for each branch recursively 
        }
    }
    return newnodes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        set<string>().swap(myset); // Clear set
        S.clear();
        cin >> N;
        S.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i]; 
        }
        long long nodes = 0;
        for (const string& s : S) {
            nodes = (nodes + dfs(s, 0) % MOD) % MOD; // Update total nodes
        }
        cout << "Case #" << t << ": " << nodes << endl;
    }
    return 0;
}
