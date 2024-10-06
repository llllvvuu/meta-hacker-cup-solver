
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
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const int M = 998244353;

long long pow_mod(long long x, long long d) {
    long long result = 1;
    while (d) {  // handle odd degree
        if (d & 1) result = result * x % M;
        d >>= 1;
        x = x * x % M;
    }
    return result;
}

int main() {
    int T; cin >> T;
    for (int case_number = 1; case_number <= T; case_number++) {
        int N; cin >> N;
        map<string, long long> prefixes;
        for (int j = 1; j <= N; j++) {
            string s; cin >> s;
            for (int i = 0; i < s.size(); i++) {
                string prefix = s.substr(0, i + 1);
                long long bitmask = 0;
                for (auto c : prefix)
                    bitmask = (bitmask << 1) + (c != '?');  // Set bit if not '?'
                auto it = prefixes.find(prefix);
                if (it == prefixes.end()) prefixes[prefix] = (1LL << (s.size() - i)) - 1;
                else it->second++;  // Increase count for seen prefixes
            }
        }
        long long result = 0;
        for (auto it = prefixes.begin(); it != prefixes.end(); ++it)
            result = (result + pow_mod(2, it->second)) % M;
        cout << "Case #" << case_number << ": " << result << endl;
    }
    return 0;
}
