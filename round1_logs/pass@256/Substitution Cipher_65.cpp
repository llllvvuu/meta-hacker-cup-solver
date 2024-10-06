
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
using namespace std;

const int MOD = 998244353;

vector<string> genSolutions(string ss, int l, int r) {
    if (l == r) return {ss.substr(l, 1)};
    if (ss[l] == '?') {
        vector<string> strings;
        if (ss[l+1] == '?') {
            for (auto sub: genSolutions(ss, l+1, r)) {
                vector<string> pointers = {"12", "22", "21", "11"};
                for (auto ptr: pointers) strings.push_back(ptr + sub);
            }
        } else if (ss[l+1] >= '1' && ss[l+1] <= '2') {
            for (auto sub: genSolutions(ss, l+1, r)) {
                strings.push_back("1" + sub);
                if (ss[l+1] == '2' && ss[l+2] <= '6')
                    strings.push_back("2" + sub);
            }
        } else {
            for (auto sub: genSolutions(ss, l+1, r)) {
                strings.push_back("1" + sub);
            }
        }
        return strings;
    }
    return genSolutions(ss, l+1, r);
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        int K;
        cin >> s >> K;
        vector<string> res = genSolutions(s, 0, s.size()-1);
        sort(res.begin(), res.end());
        cout << "Case #" << t << ": " << res[K - 1] << " " << K << endl;
    }
}
