
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
#include <fstream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

vector<bitset<102>> leaves, charMapping;
int charStart = 0x1000;

bitset<102> dp[101][1 << 10];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        leaves.clear();
        leaves.push_back(bitset<102>(1));
        for (char c = 'A'; c <= 'Z'; c++) {
            charMapping.push_back(bitset<102>(charStart));
            leaves.push_back(bitset<102>(charStart));
            charStart <<= 1;
        }
        for (int n = 0; n < N; n++) {
            string S;
            cin >> S;
            int M = S.length();
            for (int i = 0; i < 1 << M; i++) { // all combinations of wildcards 2^M
                bitset<102> path = leaves[0], new_path(path);
                string newSink;
                for (int j = 0; j < M; j++) { // for each wildcard digit
                    if (S[j] == '?') {
                        for (char c = 'A'; c <= 'Z'; c++) { // every possible wildcard character
                            char cInd = (int)(c - 'A');
                            new_path = path | charMapping[cInd];
                            newSink.push_back(c);
                            if (dp[j][new_path.to_ulong()] == 0) {
                                dp[j][new_path.to_ulong()] = 1;
                                leaves.push_back(new_path);
                            }
                            path = new_path;
                        }
                    } else {
                        char cInd = (int)(S[j] - 'A');
                        new_path = path | charMapping[cInd];
                        dp[j][new_path.to_ulong()] = 1;
                        leaves.push_back(new_path);
                        path = new_path;
                        newSink.push_back(S[j]);
                    }
                }
            }
        }
        long long res = 0;
        for (bitset<102> b: leaves) res += (b.count());
        res %= MOD;
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
