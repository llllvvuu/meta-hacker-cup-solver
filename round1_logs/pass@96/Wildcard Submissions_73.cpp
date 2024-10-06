
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
#include <cstring>
#include <string>
using namespace std;

const int MOD = 998244353;

int N;
vector<string> wildcards;

struct TrieNode {
    TrieNode *children[26] = {}; // pointer to 26 characters
    int count = 0; // number of potential words ending with this prefix
};

TrieNode *trie = new TrieNode(); // root node for the trie

void insertTrie(string s) {
    TrieNode *curr = trie;
    for (char c : s) {
        if (c == '?') {
            for (int i = 'A'; i <= 'Z'; i++) { // Checks A to Z
                if (!curr->children[i]) { // new nodes are formed
                    curr->children[i] = new TrieNode();
                }
                curr = curr->children[i];
                curr->count = (26 + curr->count) % MOD;  // Increment count modulo
            }
            return;
        } else {
            if (!curr->children[c]) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->count = (1 + curr->count) % MOD; // Update the child count for the character
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        wildcards.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> wildcards[i];
        }

        for (const string& wildcard : wildcards) {
            insertTrie(wildcard);
        }

        // Count total nodes in the trie 
        // (Precomputed over the loop)
        int totalNodes = (memset(trie, 0, sizeof(*trie)), 1);
        for (int i = 'A'; i <= 'Z'; i++) {
            totalNodes += (trie->children[i]->count > 0) ? trie->children[i]->count : 0;
        }
        
        cout << "Case #" << t << ": " << totalNodes << endl;
        // Reset the trie
        trie = new TrieNode();
    }
    return 0;
}
