
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
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX_LEN = 101;
const long long BASE = 26;
long long STRING = 0;
long long countSubs[MAX_LEN][MAX_LEN][BASE];
int N;

char wildcardStrings[27][101] = { "?", "A", "B", "C", "D", "E", 
"F", "G", "H", "I", "J",
"K", "L", "M", "N", "O",
"P", "Q", "R", "S", "T",
"U", "V", "W", "X", "Y",
"Z"};

vector<string> patterns;

void preCalculate(){
    for(int i = 0; i < MAX_LEN; i++) 
        for(int j = 0; j < MAX_LEN; j++)
            for(int k = 0; k < BASE; k++)
                countSubs[i][j][k] = 0;

    for(auto wildcard : wildcardStrings) {
        STRING = 0;
        for(int i = wildcard.length(); i > 0; i--) {
            STRING = (STRING * BASE);
            for(int c = 0; c < BASE; c++) {
                auto charCode = c + 'A' - 1;
                if(i >= wildcard.length()) charCode = '?';
                if(wildcard[i - 1] == charCode || wildcard[i - 1] == '?'){
                    countSubs[wildcard.length() - i][i - 1][c] += STRING;
                }
                countSubs[wildcard.length() - i][i - 1][c] %= MOD;
            }
        }
    }
}

long long solve() {
    long long result = 0;
    for(const auto& pattern : patterns){
        for(unsigned i = 0; i < pattern.length(); i++) 
            for(int c = 0; c < BASE; c++) {
                result += countSubs[i + 1][i][c];
                result %= MOD;
            }
        result++;
        result %= MOD;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    preCalculate();
    for (int tn = 1; tn <= t; tn++) {
        cin >> N;
        patterns.clear();
        patterns.resize(N);
        for(int i = 0; i < N; i++) 
            cin >> patterns[i];
        long long res = solve();
        cout << "Case #" << tn << ": " <<  res << endl;
    }
    return 0;
}
