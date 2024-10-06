
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
using namespace std;

const int mod = 998244353;

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
        
        vector<vector<int>> masks(1, (1 << 26) - 1);
        int maxLen = 0;
        for (const string& s : S) {
            maxLen = max(maxLen, (int)s.length());
            vector<vector<int>> newMasks(s.length() + 1);
            newMasks.back() = (1 << 26) - 1;
            for (int i = s.length() - 1; i >= 0; i--) {
                char c = s[i];
                if (c == '?') {
                    for (int j = 0; j <= i; j++) {
                        newMasks[i] = (newMasks[i] & masks[j]) << (c - 'A');
                        newMasks[i] |= masks[j] >> ('Z' - c + 1);
                    }
                } else {
                    for (int j = 0; j <= i; j++) {
                        newMasks[i] = (newMasks[i] & masks[j]) << (c - 'A');
                    }
                }
            }
            swap(masks, newMasks);
        }

        long long answer = 1;
        for (const auto& mask : masks) {
            answer = (answer * __builtin_popcountll(mask)) % mod;
        }
        cout << "Case #" << t << ": " << answer << endl;
    }
    return 0;
}
