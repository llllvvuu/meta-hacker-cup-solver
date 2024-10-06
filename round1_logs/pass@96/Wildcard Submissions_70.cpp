
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
#include <bitset>
#include <string>
using namespace std;

const int MOD = 998244353;
const int CHARSET = 26; // number of uppercase Latin letters
const int MAXLEN = 105; // length of the longest possible input string
bitset<CHARSET> bits[MAXLEN]; // bitset to keep a track of leaves at each level

// Function to propagate bitsets in a DFS manner for character 'c' as suffix
void dfs(string s, int level) {
    // If depth of current node is equal to the length of the string 's'
    if (level == s.size()) {
        // Set the respective leaf bit as 1
        bits[level][0] = true;
        return;
    }
    // If current character is '?', propagate the sum of bitsets for all possible characters
    if (s[level] == '?') {
        for (int i = 0; i < CHARSET; i++) {
            bits[level+1][i] = (bits[level+1][i] + bits[level][i]) % MOD;
        }
    } else {
        // For fixed character, propagate the respective bitset
        int c = s[level] - 'A';
        bits[level+1][c] = (bits[level+1][c] + bits[level][0]) % MOD;
    }
    // Recursive call for next level
    dfs(s, level + 1);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        bits[0][0] = 1; // Root node initialized
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            dfs(s, 0);
        }
        // Sum up the bitset for all characters in the last level
        cout << "Case #" << t << ": " << bits[s.size()][0] << endl;
    }
    return 0;
}
