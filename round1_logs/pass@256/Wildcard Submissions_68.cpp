
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
#define mod 998244353

int pow_mod(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b & 1) result = (1LL * result * a) % mod;
        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return result;
}

int solve(int N, vector<string> S) {
    int node_count = 1;  // start with the root node

    for (auto &pattern : S) {
        int current_node = 0;
        for (auto &char_i : pattern) {
            int index = (char_i != '?') ? (char_i - 'A') : 26;
            int next_index = (current_node * 27 + index) % mod;
            if (next_index == current_node) continue;  // duplicate path, no new node
            else {
                node_count++;
                current_node = next_index;
            }
        }
        // Account for the full subtree if a "?" ended the pattern
        if (char_i == '?') {
            int l = (int)pattern.length() - (pattern.find_last_of("?") + 1);
            node_count = (node_count + 1LL * pow_mod(26, l) * (N - 1)) % mod;
        }
    }
    return node_count % mod;
}
