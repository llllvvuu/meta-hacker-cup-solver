
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
#include <unordered_set>
const long long prime = 998244353, base = 26;
unordered_set<long long> ws[101]; // (empty set), S1, S2, ...

long long addition(long long hash, char c) {
    long long res = hash * base % prime;
    return (res + (c == '?' ? base - 1 : (c - 'A'))) % prime;
}

void insert_str(unordered_set<long long> &hs, string s) {
    long long hash{}; 
    for (char c : s)
        hash = addition(hash, c), ws[hash].insert(hash);
}

void practicalSolution() {
    int T; std::cin >> T;
    for (int t{1}; t <= T; ++t) {
        int N; std::cin >> N;
        long long res{1}; // Trie root
        
        for (int i{1}; i <= N; ++i) {
            unordered_set<long long> ns{1}; // one-level prefix
            for (char c; std::cin >> c; ns = std::move(ws[c == '?' ? base : (c - 'A')])) // forward[base]
                for (auto hash : ns) // Carry and addition in this loop
                    ns.insert(addition(hash, c)); // addition(hash, c)
            res += (res + ns.size()) % prime; // triangle number sum: 1, 3, 6, 10, ... 
        }
        
        std::cout << "Case #" << t << ": "; 
        for (int i{1}; i < 100; ++i) ws[i].clear();
        std::cout << res % prime << '\n';
    }
}
int main() {
    practicalSolution();
    return 0;
}
