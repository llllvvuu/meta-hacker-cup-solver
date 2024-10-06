
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
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

void insert(string& s, int i, TrieNode* root, long long& result) {
    if (i >= s.length()) return;
    
    // Check if current subtree has a corresponding children set.
    if (root->children.count(s[i]) == 0) {
        // If new subtree, add it.
        root->children[s[i]] = new TrieNode();
        
        // If current character is '?' or the last character, increment result.
        int charsLeft = (s[i] == '?' || i == s.length() - 1 ? 26 : 1);
        result = (result + charsLeft) % 998244353;
    }
    
    insert(s, i + 1, root->children[s[i]], result);
}

int solve(int N, vector<string>& S) {
    TrieNode root;
    long long result = 0;

    for (auto& s : S) {
        insert(s, 0, &root, result);
    }
    
    // Add root node
    result = (result + 1) % 998244353;

    return result;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        cout << "Case #" << t << ": " << solve(N, S) << endl;
    }
    return 0;
}
