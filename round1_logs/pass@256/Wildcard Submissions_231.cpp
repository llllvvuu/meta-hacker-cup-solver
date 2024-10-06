
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
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

const int M = 998244353;
const int P = 9973;
const int MOD = 9973; // prime number for modulo

// Function to perform hashing
unsigned long long hashe(string &s) {
    unsigned long long res = 0;
    for (char c : s) {
        res = (res * P + c) % MOD;
    }
    return res;
}

// Function to generate and count all unique substrings
int solve(int N, const vector<string> &S) {
    unordered_map<unsigned long long, int> seen;
    set<string> unique_s;
    for (int i = 0; i < N; i++) {
        if (!S[i].empty()) {
            unique_s.insert(S[i]);
        }
    }
    for (const string &s : unique_s) {
        for (int i = 0; i < s.length(); i++) {
            for (char c = 'A'; c <= 'Z'; c++) {
                if (s[i] == '?') {
                    string new_s = s;
                    new_s[i] = c;
                    unique_s.insert(new_s);
                }
            }
        }
    }

    int total_nodes = 0;
    for (const string &s : unique_s) {
        seen.clear();
        bool past_prefix = false;
        for (char c : s) {
            if (seen.count(hashe(s.substr(0, s.find(c) + 1))) == 0 || !past_prefix) {
                total_nodes++;
                past_prefix = true;
            }

            seen[hashe(s.substr(0, s.find(c) + 1))]++;
        }
    }
    return total_nodes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        vector<string> S(N);
        for (int j = 0; j < N; j++) {
            cin >> S[j];
        }
        cout << "Case #" << i << ": " << solve(N, S) << endl;
    }
    return 0;
}
