
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
#include <unordered_map>
#include <string>
using namespace std;

const int MOD = 998244353;

struct TrieNode {
    unordered_map<int, TrieNode*> children;
};

unordered_map<int, bool> done;
TrieNode root;
int cnt;

void buildTree(const string& pattern) {
    TrieNode *last = &root;
    for (char ch:pattern) {
        if (ch == '?') {
            for (int i = 0; i < 26; i++) {
                int c = 'A'+i;
                if (last->children.count(c) == 0) {
                    last->children[c] = new TrieNode();
                    cnt++;
                }
                last = last->children[c];
            }
        } else {
            int c = ch;
            if (last->children.count(c) == 0) {
                last->children[c] = new TrieNode();
                cnt++;
            }
            last = last->children[c];
        }
    }
}

// Use string hashing to uniquely identify each branch generated.
int hash_s(string s) {
    int hash = 0;
    int p = 31, q = MOD;
    for (char ch : s) {
        hash += (ch - 'A' + 1)*p;
        p *= q;
    }
    return hash % MOD;
}

void solve(string S) {
    buildTree(S);
    for (int i = 1; i < S.size(); i++) {
        string prefix = S.substr(0, i);
        if (done.count(hash_s(prefix))) continue;
        for (char c = 'A'; c <= 'Z'; c++) {
            string new_p = prefix + c;
            buildTree(new_p);
            done[hash_s(prefix)] = true;
        }
    }
    done[hash_s(S)] = true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cnt = 1; // Count the root node.
        done.clear();
        for (int i = 0; i < N; i++) {
            string S;
            cin >> S;
            solve(S);
        }
        cout << "Case #" << t << ": " << cnt % MOD << endl;
    }
    return 0;
}
