
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
#include <unordered_map>
using namespace std;

const int mod = 998244353;

unordered_map<char, int> trie;

// Recursively count nodes for a string
int count_nodes_helper(const string &s, int size) {
    if (size == 0) return 1; // Base case: empty string or leaf node reached
    if (trie.count(s.substr(0, size))) return trie[s.substr(0, size)]; // Found in cache, return

    string key = s.substr(0, size);
    long long count = 1; // Count for the node

    // Visit all children representing characters (non-wildcard)
    for (char c = 'A'; c <= 'Z'; c++) {
        if (s[size - 1] == '?' || s[size - 1] == c) {
            // If we have a wildcard or matching char, try to add it
            count += count_nodes_helper(key + c, size + 1);
            count %= mod;
        }
    }

    // Store in cache
    trie[key] = count;
    return count;
}

// Function to add a wildcard and count nodes
int count_nodes(const string &s) {
    return count_nodes_helper("", 0) * 26; // Start from empty prefix and multiply by 26 for wildcards
}

int main() {
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        int result = 1; // Keep 1 for the empty prefix
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            result *= count_nodes(s);
            result %= mod;
        }

        // Output result
        cout << "Case #" << t << ": " << result << endl;
        trie.clear(); // Clear the trie for the next test case
    }
    return 0;
}
