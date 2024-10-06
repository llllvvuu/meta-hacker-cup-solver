
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
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int mod = 998244353;

void add(const string &s, unordered_map<string, bool> &seen, long long &cnt) {
    string prefix = "";
    cnt = 0;
    for (char ch: s) {
        if (ch == '?') {
            for (char c = 'A'; c <= 'Z'; ++c) {
                prefix.push_back(c);
                if (seen[prefix] == false) {
                    seen[prefix] = true;
                    ++cnt;
                }
                prefix.pop_back();
            }
        } else {
            prefix.push_back(ch);
            if (seen[prefix] == false) {
                seen[prefix] = true;
                ++cnt;
            }
        }
    }
}

long long insert_wildcard(string s, unordered_map<string, bool> &seen) {
    long long result = 1;
    result = (result + add(s, seen)) % mod;
    return result;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        unordered_map<string, bool> seen;
        seen.clear();
        long long total_nodes = 1;
        for (int j = 0; j < N; ++j) {
            string s;
            cin >> s;

            long long node_count = insert_wildcard(s, seen);
            total_nodes = (total_nodes + node_count - 1) % mod;
        }

        cout << "Case #" << i << ": " << total_nodes << "\n";
    }
    return 0;
}
