
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
#include <algorithm>

using namespace std;

// Function to find all possible strings from the wildcard pattern and count nodes
void solve_case() {
    int N, result = 1;  // 1 for the root node
    string S;
    vector<string> possibilities;

    cin >> N;

    // Generate and insert all possible strings into the map for this test case
    for (int i = 0; i < N; i++) {
        cin >> S;

        // Find all strings by generating permutations with `?` replaced by any characters
        vector<string> expansion;
        int start = 1, end = 1;
        for (char ch : S) {
            if (ch == '?') {
                end *= 26;
            } else {
                if (end > start) {
                    for (int k = start, limit = end; k < limit; k += 26) {
                        possibilities.push_back(S);
                        possibilities.back().replace(i, 1, 1, 'A' + (k - start) / 26);
                    }
                    start = end;
                }
                start *= 26;
                possibilities.back().replace(i, 1, 1, ch);
            }
        }

        // Add remaining variations ending with `?`
        for (int k = start, limit = end; k < limit; k += 26) {
            possibilities.push_back(S);
            possibilities.back().replace(i, 1, 1, 'A' + (k - start) / 26);
        }

        // Map each possible string to its prefix
        for (auto & p : possibilities) {
            for (int i = 0, len = p.size(); i < len; i++) {
                if (p[i] == '?') {
                    break;
                }
            }

            p.resize(i);
            result += static_cast<int>(1 + p.size());
        }
        possibilities.clear();
    }

    cout << result << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve_case() % 998244353 << '\n';
    }
    return 0;
}

