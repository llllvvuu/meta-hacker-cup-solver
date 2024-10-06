
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
#include <unordered_set>
#include <string>
using namespace std;

const unsigned MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        unordered_set<string> seen;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int a = 0; a < (1 << 26); a++) {
                for (int j = 0; j < s.size(); j++) {
                    if (s[j] == '?') {
                        s[j] = 'A' + (a & (1 << j));
                    }
                }
                string pref = "";
                seen.insert(pref);
                for (char c: s) {
                    pref += c;
                    seen.insert(pref);
                }
            }
        }

        cout << "Case #" << t << ": ";
        cout << ((int)seen.size()) % MOD << "\n";
    }

    return 0;
}
