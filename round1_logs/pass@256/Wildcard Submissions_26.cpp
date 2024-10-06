
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
#include <set>
using namespace std;

const int MOD = 998244353;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (int i = 0; i < N; i++) {
            cin >> S[i];
        }
        sort(S.rbegin(), S.rend(), [](string& a, string& b) { return a.size() > b.size(); });

        set<string> seen = {""};
        long long last = 1;
        for (int i = 0; i < N; i++) {
            string s = S[i];
            int ending = s.size() - seen.count(s);
            for (int j = 0; j < s.size(); j++) {
                if (s[j] != '?') {
                    s = s.substr(0, j) + s.substr(j + 1);
                }
            }
            if (seen.count(s)) {
                last += ending;
                last %= MOD;
            } else {
                seen.insert(s);
                last = (last * 26 + ending) % MOD;
            }
        }
        cout << "Case #" << t << ": " << last << endl;
    }
    return 0;
}
