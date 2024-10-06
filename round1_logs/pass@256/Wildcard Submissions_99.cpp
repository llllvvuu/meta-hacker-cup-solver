
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
#include <map>
#include <iostream>
#include <string>
using namespace std;

const int MOD = 998244353;

int solve(string str) {
    map<long long, int> mp;
    int N = str.length();
    long long node = 0;
    
    // Iterate through all possible prefixes within the wildcard
    for(int i = 0; i <= N; i++) {
        long long hashValue = 1;
        for(int j = i; j < N; j++) {
            if (str[j] == '?') {
                mp[hashValue] += 26;
                mp[hashValue * pow(26, j-i+1)]--;
                mp[hashValue * pow(26, j-i+2)] += 26;
            } else {
                mp[hashValue]++; // Full match
                hashValue = hashValue * 26 + (str[j] - 'A') + 1;
            }
            mp[hashValue]++;
        }
    }
    
    node = 1; // root node
    for (auto x : mp)
        node = (node + x.second) % MOD;
    return (int)node - 1;
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int N; cin >> N;
        string str;
        for (int j = 0; j < N; j++) {
            cin >> str;
            cout << "Case #" << i << ": " << solve(str) % MOD << "\n";
        }
    }
    return 0;
}
