
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

const long long MOD = 998244353;

long long getHash(string &s, long long base = 29, long long mod = MOD) {
    long long h = 0, p = 1;
    for (char c : s) {
        h = (h + p * (c - 'A' + 1)) % mod;
        p = (p * base) % mod;
    }
    return h;
}

vector<long long> getPrefixes(string s) {
    int n = s.size();
    vector<long long> hashes;
    hashes.push_back(0); // for empty prefix
    for (int i = 1; i <= n; i++) {
        for (char c = 'A'; c <= 'Z'; c++) {
            string prefix = s.substr(0, i);     // current prefix being checked
            if (prefix[n-1] == '?') {           // Replace '?' with the current character if needed
                prefix[n-1] = c;
                hashes.push_back(getHash(prefix));
            }
        }
    }
    return hashes;
}

unordered_set<long long> existingNodes;

long long insertWildCard(string &s) {
    long long totalNodes = 0;
    for (char &c : s) {
        if (c != '?') {
            existingNodes.insert(getHash({c}));
        } else {
            break;
        }
    }
    else return s.size(); // match insertion without '?' characters

    vector<long long> prefixes = getPrefixes(s);
    for (long long h : prefixes) {
        if (existingNodes.find(h) == existingNodes.end()) {
            existingNodes.insert(h);
            totalNodes++;
        }
    }
    return totalNodes;
}

long long solve() {
    long long N;
    cin >> N;
    long long totalNodes = 1; // Initial root node for the trie.
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        totalNodes += insertWildCard(S);
        totalNodes %= MOD;
    }
    return totalNodes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        existingNodes.clear();
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
