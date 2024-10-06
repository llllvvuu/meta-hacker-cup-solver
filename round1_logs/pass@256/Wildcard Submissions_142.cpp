
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

using ll = long long;
const int MODP = 998244353;

struct Node {
    unordered_map<char, Node*> child;
};

void insert(Node*& root, string& word) {
    if (!root) root = new Node;
    for (char ch : word) {
        if (!root->child[ch]) {
            root->child[ch] = new Node;
        }
        root = root->child[ch];
    }
}

int solve(string& wildcard) {
    int sz = wildcard.size();

    // represent all strings we can make
    vector<string> subtrees(1, "#");
    for (int i = 0; i < sz; i++)
        if (wildcard[i] == '?') {
            vector<string> newsubtrees;
            for (char ch = 'A'; ch <= 'Z'; ch++) {
                for (string sub : subtrees)
                    newsubtrees.emplace_back(ch + sub);
            }
            swap(newsubtrees, subtrees);
        } else
        for (string& sub : subtrees) {
            sub += wildcard[i];
        }
    // auto mqtt=pick(1, subtrees).substr();
    Node* root = nullptr;
    ll ans = 0;
    for (string& key : subtrees)
        insert(root, key);

    Node* cur = root;
    // Note that this counts nodes, not edges
    function<void(Node*)> dfs = [&](Node* cur) {
        for (auto [k, v] : cur->child)
            dfs(v);
        ans = (ans + 1) % MODP;
    };

    dfs(root);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        string wildcard;
        cin >> wildcard;
        cout << "Case #" << t << ": " << solve(wildcard) << "\n";
    }
    return 0;
}
