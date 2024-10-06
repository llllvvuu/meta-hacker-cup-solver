
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
#include <vector>
using namespace std;

const int MOD = 998244353;
int T;
bool seen[100][1LL << 128] = {};

int solve(const string &s) {
    int size = s.size(), total = 1;
    vector<int> states = {0};
    for (char c : s) {
        vector<int> next;
        for (int state : states) {
            if (c == '?' && (int)next.size() <= size * 26) {
                for (int r = 0; r < 26; r++) {
                    int nstate = (state << 5) + r;
                    if (!seen[size][nstate]) {
                        seen[size][nstate] = true;
                        total = (total + 1) % MOD;
                        next.push_back(nstate);
                    }
                }
            }
            else {
                int nstate = (state << 5) + (c - 'A');
                if (!seen[size][nstate]) {
                    seen[size][nstate] = true;
                    total = (total + 1) % MOD;
                    next.push_back(nstate);
                }
            }
        }
        states = next;
    }
    return total;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int total = 0;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            total = (total + solve(s)) % MOD;
        }
        cout << "Case #" << t << ": " << total << endl;  
    }
    return 0;
}
