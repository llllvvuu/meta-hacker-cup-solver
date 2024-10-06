
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
#include <cassert>
#include <map>
using namespace std;

const int PRIME = 998244353;

// Recursive function to count nodes
map<pair<int, string>, long long> memo;

long long count_nodes(int pos, const string &wildcard) {
    if (memo.find({pos, wildcard}) != memo.end()) return memo[{pos, wildcard}];
    if (pos >= wildcard.size()) return 1; // Base case: ony one way to process an empty input
    
    long long ans = 0;
    // Loop to find all partitions of the string at every `?`
    for (int i = pos; i < wildcard.size(); ++i) {
        if (wildcard[i] == '?') {
            string prefix = wildcard.substr(pos, i - pos);
            ans += (count_nodes(i + 1, wildcard) * (prefix.empty() ? 1 : 26)) % PRIME;
            ans %= PRIME;
        }
    }
    memo[{pos, wildcard}] = ans;
    return ans;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> wildcards(N);
        for (int i = 0; i < N; i++) cin >> wildcards[i];
        
        long long total_nodes = 1; // Node for the empty prefix
        for (const string &wildcard : wildcards)
            total_nodes = (total_nodes + count_nodes(0, wildcard) - 1) % PRIME;
        
        cout << "Case #" << t << ": " << total_nodes << '\n';
    }
    return 0;
}
