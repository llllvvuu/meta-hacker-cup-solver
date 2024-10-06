
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
#include <vector>
using namespace std;

const int mod = 998244353;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count;
};

void insert(TrieNode* root, string& wildcard) {
    TrieNode* curr = root;
    for (char& c : wildcard) {
        if (c == '?') break;
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
        curr->count++;
    }
}

void insertWQuery(TrieNode* root, string& wildcard) {
    TrieNode* curr = root;
    int mul = 1;
    for (char& c : wildcard) {
        if (c == '?') break;
        if (curr->children.find(c) == curr->children.end()) {
            curr->children[c] = new TrieNode();
            curr->children[c]->count = 1;
        }
        curr = curr->children[c];
    }
    int qCount = int(wildcard.size()) - int(curr->children.size());
    for (int k = 0; k < qCount; k++) {
        mul = (mul * 26) % mod;
    }
    curr->count = (curr->count + mul + mod) % mod;
}

int countNodes(TrieNode* root) {
    if (!root) return 0;
    int total = root->count;
    for (auto& pair : root->children) {
        total += countNodes(pair.second);
    }
    return total;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        TrieNode* root = new TrieNode();
        root->count = 1;
        int N;
        cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
            insertWQuery(root, S[i]);
        }
        int result = countNodes(root);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}
