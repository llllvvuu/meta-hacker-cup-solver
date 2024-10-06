
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
#include <unordered_set>

const int MOD = 998244353;

struct Node {
    int is_word;
    Node* children[26];  // Assuming uppercase only; No '?' wildcards in Node data structure itself

    Node() : is_word(0) {
        std::fill(children, children + 26, nullptr);
    }

    void insert(const std::string& wildcard, int i, Node* parent, std::unordered_set<std::pair<Node*, Node*>>& visited) {
        if (i == wildcard.size()) { 
            visited.insert({this, parent});
            return; 
        }
        
        if (wildcard[i] == '?') {
            for (int j = 0; j < 26; ++j) {
                if (!children[j]) {
                    children[j] = new Node();
                }
                children[j]->insert(wildcard, i + 1, this, visited);
            }
        } else {
            int idx = wildcard[i] - 'A';
            if (!children[idx]) {
                children[idx] = new Node();
            }
            children[idx]->insert(wildcard, i + 1, this, visited);
        }
    }

    ~Node() {
        for (auto& child : children)
            if (child)
                delete child;
    }
};

int main() {
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        std::cin >> N;
        Node root;
        std::unordered_set<std::pair<Node*, Node*>> visited;
        visited.insert({&root, nullptr});
        for (int i = 0; i < N; ++i) {
            std::string S;
            std::cin >> S;
            root.insert(S, 0, &root, visited);
        }
        long long ans = visited.size();
        std::cout << "Case #" << t << ": " << (ans % MOD) << "\n";
    }
    return 0;
}
