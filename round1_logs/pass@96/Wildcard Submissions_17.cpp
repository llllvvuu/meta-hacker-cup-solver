
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
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

struct Node {
    Node* children[26] = {nullptr};
    bool isEnd = false;
};

Node* insert(Node* cur, string& s, int i) {
    if (cur == nullptr) {
        cur = new Node();
    }
    if (i == s.size()) {
        cur->isEnd = true;
        return cur;
    }
    if (s[i] == '?') {
        for (char c = 'A'; c <= 'Z'; c++) {
            cur->children[c - 'A'] = insert(cur->children[c - 'A'], s, i + 1);
        }
        cur->isEnd = true;
    } else {
        cur->children[s[i] - 'A'] = insert(cur->children[s[i] - 'A'], s, i + 1);
    }
    return cur;
}

long long dfsNodeCount(Node* cur) {
    if (cur == nullptr) return 0;
    long long cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (cur->children[i]) {
            cnt += dfsNodeCount(cur->children[i]) % mod;
            cnt %= mod;
        }
    }
    return (cnt + cur->isEnd) % mod;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        Node* root = new Node();
        vector<string> wildcards(N);
        for (int i = 0; i < N; i++) cin >> wildcards[i];
        for (auto& s : wildcards) {
            insert(root, s, 0);
        }
        cout << "Case #" << t << ": " << dfsNodeCount(root) << '\n';
        delete root;
    }
    return 0;
}
