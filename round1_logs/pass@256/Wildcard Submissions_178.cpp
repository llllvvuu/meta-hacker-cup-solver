
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
#include <unordered_set>
using namespace std;

int N, totalNodes;

const int MOD = 998244353;
vector<string> patterns;
vector<unordered_map<char, int>> trie;
unordered_set<int> visited;
 
void dfsCase(int i, int par) {
    if (visited.find(par) == visited.end() && visited.size() < N) {
        visited.insert(par);
        totalNodes += i;
    }
    int edgeCount = i * 26 % MOD;

    auto& children = trie[par];
    for (int c = 0; c < patterns[par].size(); c++) {
        if (children.find(patterns[par][c]) == children.end()) {
            children[patterns[par][c]] = edgeCount++;
        }
        dfsCase(i + 1, children[patterns[par][c]]);
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        patterns.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> patterns[i];
        }
        trie.assign(N+1, unordered_map<char, int>());
        visited.clear();
        visited.insert(0);
        totalNodes = 1;  // Should have at least one: the root

        dfsCase(1, 0);

        cout << "Case #" << t << ": " << totalNodes % MOD << endl;
    }
    return 0;
}
