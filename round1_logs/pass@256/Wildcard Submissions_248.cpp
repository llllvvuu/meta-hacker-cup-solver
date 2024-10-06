
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
#include <unordered_set>

using namespace std;
const int MOD = 998244353;

unordered_set<string> uniquePrefixes;

int dfs(const string& wildcard) {
    int unique = 0;
    auto it = uniquePrefixes.insert(wildcard);
    if (it.second) unique = 1;

    for (char& c : wildcard) {
        if (c == '?') {
            for (char nextChar = 'A'; nextChar <= 'Z'; nextChar++) {
                c = nextChar;
                unique = (unique + dfs(wildcard.substr(1))) % MOD;
            }
            c = '?'; // backtrack
        }
        wildcard = wildcard.substr(1); // move to the next character
        it = uniquePrefixes.insert(wildcard);
        if (it.second) unique = (unique + 1) % MOD;
    }
    return unique;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        uniquePrefixes.clear();
        uniquePrefixes.insert(""); // the empty string node

        int totalUniqueNodes = 0;
        uniquePrefixes.clear();
        for (int i = 0; i < N; i++) {
            string wildcard;
            cin >> wildcard;
            totalUniqueNodes = (totalUniqueNodes + dfs(wildcard)) % MOD;
        }

        cout << "Case #" << T+1 << ": " << totalUniqueNodes << endl;
    }
    return 0;
}
