
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
#include <bitset>
#include <vector>
using namespace std;

bitset<1000000> masks[26]; // to map each prefix to a node
int mod = 998244353;

void dfs(vector<bitset<1000000>>& ms, int i, bitset<1000000> newMask) {
    if (i == ms.size()) {
        return;
    }
    dfs(ms, i + 1, newMask & ms[i]);
    dfs(ms, i + 1, newMask);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<bitset<1000000>> masksRep(N);
        for (int i = 0; i < N; i++) {
            string S;
            cin >> S;
            for (int j = 0; j < S.length(); j++) {
                if (S[j] == '?') {
                    for (int c = 0; c < 26; c++) {
                        masksRep[i][masks[c][S.length() - j - 1]] = 1;
                    }
                } else {
                    masksRep[i][masks[S[j] - 'A'][S.length() - j - 1]] = 1;
                }
            }
            masksRep[i][1] = 1; // root node
        }
        bitset<1000000> finalMask;
        dfs(masksRep, 0, finalMask);
        int result = 0;
        for (int i = 0; i < 1000000; i++) {
            if (finalMask[i]) result++;
        }
        cout << "Case #" << t << ": " << result % mod << endl;
    }
    return 0;
}
