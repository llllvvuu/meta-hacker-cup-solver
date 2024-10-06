
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
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

typedef long long ll;
const int M = 998244353;

void insert_trie(unordered_map<string, int> &trie, string str, int &ans) {
    int curr = 0;
    for (char ch : str) {
        if (ch != '?') {
            string key = to_string(curr) + ch;
            if (trie.find(key) == trie.end()) {
                trie[key] = (curr == 0 ? 1 : trie[to_string(curr)]);
                ans = (ans + trie[key]) % M;
            }
            curr = trie[key];
        } else {
            for (char c = 'A'; c <= 'Z'; c++) {
                string key = to_string(curr) + c;
                if (trie.find(key) == trie.end()) {
                    trie[key] = (curr == 0 ? 1 : trie[to_string(curr)]);
                    ans = (ans + trie[key]) % M;
                }
            }
            curr = trie[to_string(curr)];
        }
    }
    string key = to_string(curr);
    if (trie.find(key) == trie.end()) {
        trie[key] = 1;
        ans = (ans + 1) % M;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T, N;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        unordered_map<string, int> trie;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;
            insert_trie(trie, str, ans);
        }
        cout << "Case #" << t << ": " << ans << '\n';
    }
    return 0;
}
