
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
#include <algorithm>
using namespace std;

vector<string> parse_wildcards(const string& s) {
    vector<string> results;
    results.push_back(""); // root '""'
    for (char c : s) {
        int n = results.size();
        if (c == '?') {
            for (int i = 0; i < n; ++i)
                results.push_back(results[i] + 'A');
            for (int i = 0; i < n; ++i)
                results[i] += '?';
        } else {
            for (int i = 0; i < n; ++i)
                results[i] += c;
        }
    }
    return results;
}

long long count_nodes(const vector<string>& wildcards) {
    const int mod = 998244353;
    vector<bool> cnt(100 * 26 + 1, false);
    for (string wildcard : wildcards)
        if ((int)(wildcard.length()) <= 100 * 26)
            cnt[(int)(wildcard.length())] = true;
    long long result = 0;
    for (int i = 1; i <= 100 * 26; ++i)
        if (cnt[i])
            result = (result + (i % mod) * (26 % mod) % mod) % mod, cnt[i - 1] = true;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T, N;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        string input;
        vector<string> parsed_input;
        for (int i = 0; i < N; ++i) {
            cin >> input;
            parsed_input.insert(parsed_input.end(), parse_wildcards(input).begin(), parse_wildcards(input).end());
        }
        cout << "Case #" << t << ": " << count_nodes(parsed_input) << '\n';
    }
}
