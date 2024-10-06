
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
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 26;
const int MOD = 998244353;

// Trie node structure
struct TrieNode {
    vector<unsigned long long> children;

    TrieNode() : children(ALPHABET_SIZE) {}

    unsigned long long& operator[](char c) {
        return children[c - 'A'];
    }
};

string S;
int n;
vector<TrieNode> trie;
unsigned long long dp[266];

int64_t solve() {
    cin >> n;
    cin >> S;
    n--;
    trie.push_back(TrieNode());
    dp[0] = 1; 
    long long res = 1;

    while (n--) {
        cin >> S;
        res = 0;
        for (int i = 0; i < S.size(); i++) {
            TrieNode next = TrieNode();
            for (int c = 0; c < ALPHABET_SIZE; c++) {
                unsigned long long prev = dp[i], cur = 0;

                if (S[i] == '?') {
                    cur = prev;
                    prev = 0;
                } else {
                    cur = prev * (S[i] == char('A' + c));
                }

                res = (res + cur * (next[c] - prev)) % MOD;
                dp[i + 1] = (dp[i + 1] + prev) % MOD;
                next[c] = (next[c] + prev) % MOD;
            }
            trie.push_back(next);
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << "\n";
    }
    return 0;
}
