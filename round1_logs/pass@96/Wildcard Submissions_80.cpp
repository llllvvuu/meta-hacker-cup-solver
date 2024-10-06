
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
#include <map>
#include <string>
#include <vector>
using namespace std;

const int MOD = 998244353;

// Function to generate all possible strings from a wildcard pattern
void generateSubstring(string &s, vector<string> &splits, int depth = 0) {
    bool qSeen = false;
    for (int i = 0; i < depth; i++) {
        if (qSeen) {
            break;
        }
        for (char c = 'A'; c <= 'Z'; ++c) {
            splits.push_back(s);
            if (s[depth - (i + 1)] == '?') {
                qSeen = true;
            }
            s[depth - (i + 1)] = c;
            if (i + 1 < depth) {
                generateSubstring(s, splits, depth);
            }
        }
        if (qSeen) {
            break;
        }
        s[depth - (i + 1)] = '?';
    }
}

// Function to count nodes in the trie
int countNodes(const vector<string> &words) {
    map<string, long long> trie;
    long long totalNodes = 1; // Node for the empty string "''"

    for (const string &word : words) {
        string prefix = "";
        for (char c : word) {
            prefix += c;
            trie[prefix]++;
            if (trie[prefix] == 1) {
                totalNodes = (totalNodes + 1) % MOD;
            }
        }
    }

    return totalNodes;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; ++i) {
            cin >> words[i];
        }

        vector<string> allWords;
        for (string word : words) {
            vector<string> splits;
            generateSubstring(word, splits);
            allWords.insert(allWords.end(), splits.begin(), splits.end());
        }

        cout << "Case #" << t << ": " << countNodes(allWords) << endl;
    }
    return 0;
}
