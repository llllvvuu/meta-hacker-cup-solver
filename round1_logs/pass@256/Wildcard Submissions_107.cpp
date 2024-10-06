
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
#include <array>
#include <iostream>
#include <map>
#include <unordered_map>
#define MOD 998244353

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        // Read the current case's inputs
        int N;
        cin >> N;
        char buffer[1024];
        
        // Use a map to count unique paths in the trie
        map<array<int, 2>, long long> paths;

        // Loop through all strings in this case
        for (int i = 0; i < N; ++i) {
            cin.getline(buffer, 1024);
            
            long long base = 1, h = 0;
            int unique = 1;

            // Calculate hash h for each character
            for (auto ch : buffer) {
                if (ch == '?') {
                    h = (h * 26 + base - 1) % MOD;
                    base = base * 26 % MOD;
                } else {
                    h = (h * 26 + ch - 'A' + 1) % MOD;
                }
                // Increment count in map (creates/uses new entry if necessary)
                auto it = paths.find({h, unique});
                if (it == end(paths))
                    it = paths.emplace({h, unique}, 0).first;
                it->second++;
            }
            // Record depth of last character; unique dynamically updated
            while (paths.count({h, unique++}));
        }

        // Finalize results
        long long result = 1;
        for (auto [_, amt] : paths) {
            result = (result + amt) % MOD;
        }
        
        // Output for current case
        cout << "Case #" << t << ": " << result << '\n';
    }
    return 0;
}
