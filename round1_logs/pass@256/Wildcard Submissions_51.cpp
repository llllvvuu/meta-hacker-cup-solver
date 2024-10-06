
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
#include <map>
#include <set>
#include <string>
using namespace std;

const int MOD = 998244353;

int countTrieNodes(const vector<string>& patterns) {
    set<string> seen{{""}};
    for (const string& pattern : patterns) {
        set<string> temp;
        for (const string& pre : seen) {
            for (char ch : pattern) {
                if (ch == '?') {
                    for (char j = 'A'; j <= 'Z'; ++j) {
                        temp.insert(pre + j);
                    }
                } else {
                    temp.insert(pre + ch);
                }
            }
        }
        for (const string& str : temp) {
            seen.insert(str);
        }
    }
    return seen.size() % MOD;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> patterns(N);
        for (int i = 0; i < N; i++) {
            cin >> patterns[i];
        }
        cout << "Case #" << t << ": " << countTrieNodes(patterns) << endl;
    }
    return 0;
}
