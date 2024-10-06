
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
#include <cstdint>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MOD = 998244353;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> strings(N);
        for (int i = 0; i < N; i++) {
            cin >> strings[i];
        }
        size_t total_nodes = 0;
        std::set<string> unique;
        unique.insert(""); // root
        for (const auto &wildcard : strings) {
            for (size_t i = 0; i < wildcard.length(); i++) {
                if (wildcard[i] == '?')
                    break;
                auto hash = unique.end();
                unique.emplace(wildcard.substr(0, i + 1));
            }              
        }             
        total_nodes = unique.size();
        cout << "Case #" << t << ": " << total_nodes % MOD << endl;
    }
    return 0;
}
