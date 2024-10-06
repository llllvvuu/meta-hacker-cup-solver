
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

const long long int MOD = 998244353;

long long int countNodes(const string &s) {
    vector<long long int> counts(s.size() + 1, 1); // counts[i] is the number of ways to represent the first i characters
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            counts[i+1] = (26 * counts[i]) % MOD;
        } else {
            counts[i+1] = counts[i];
        }
    }
    long long int ans = (counts.back() * (counts.back() + 1) / 2) % MOD;
    return ans;
}

int main() {
    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; t++) {
        int N;
        cin >> N;
        long long int nodes_sum = 0;
        for (int n = 0; n < N; n++) {
            string s;
            cin >> s;
            nodes_sum = (nodes_sum + countNodes(s)) % MOD;
        }
        cout << "Case #" << t << ": " << nodes_sum << endl;
    }
    return 0;
}
