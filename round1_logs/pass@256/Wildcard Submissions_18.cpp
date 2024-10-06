
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

const int MOD = 998244353;

struct Node{
    int index;
    unordered_map<char, Node> children;
    Node(int i) : index(i) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t = 1; t <= T ; t++) {
        int N;
        cin >> N;
        Node root(-1);

        for(int i = 0 ; i < N; i++) {
            string s;
            cin >> s;
            Node *temp = &root;
            for(char c: s) {
                if (c == '?')
                    for(char cc : "ABCDEFGHIJKLMNOPQRSTUVWXYZ")
                        temp->children[cc] = Node(max(temp->index + 1, 0));
                else
                    temp->children[c] = Node(max(temp->index + 1, 0));
                temp = &temp->children[c];
            }
        }

        int result = 0;
        queue<pair<Node*, int>> q;
        q.push({&root, root.index});
        while(!q.empty()) {
            Node* n = q.front().first;
            int p = q.front().second;
            q.pop();
            int qindex = 0;
            for(auto& p : n->children)
                q.push({&p.second, max(p.second.index, qindex++)});
            result += max(0, n->index - p) % MOD;
        }

        cout << "Case #" << t << ": " << result << endl;
    }

    return 0;
}
