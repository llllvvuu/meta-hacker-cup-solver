
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
const int mod = 998244353;

int totalNodes;

void merge(string& cur, const string& A) {
    int idx = 0;
    for (char c : A) {
        if (c == '?') {
            for (char c2 = 'A'; c2 <= 'Z'; c2++) {
                cur[idx] = c2;
                merge(cur, A);
            }
            return;
        }
        if (cur[idx] == 0) cur[idx] = c;
        if (cur[idx] != c) {
            cur[idx] = '#'; // Invalid path
            return;
        }
        idx++;
    }
    // If end of A is reached, we have a valid node
    while (idx < cur.size() && cur[idx]) idx++;
    if (idx == cur.size()) totalNodes = (totalNodes + 1) % mod;
}

void go(string S) {
    int N = S.size();
    string cur(N, 0);
    merge(cur, S);
}

int solution() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (string& s : S) cin >> s;
    totalNodes = 1; // root node
    for (string& s : S) {
        go(s);
    }
    return totalNodes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solution() << endl;
    }
    return 0;
}
