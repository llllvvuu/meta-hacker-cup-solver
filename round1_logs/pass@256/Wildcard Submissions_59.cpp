
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

long long MOD = 998244353;

long long dfs(string s, map<string,int>& trie) { 
    if (trie.find(s) == trie.end()) 
        trie[s] = 1; 
    else 
        trie[s]++; 

    if (s.size() < 1) 
        return 0; 

    for (int i = 0; i < s.size(); i++) { 
        for (int j = 0; j < 26; j++)  
            trie[s.substring(1,s.size() - 1) + (char)(j + 'A')] += 
                       dfs(s.substring(1,i) + (char) '?' + s.substring(i+1), trie); 

        dfs(s.substring(0,i) + (char) '?' + s.substring(i+1), trie); 
    } 

    return trie[s]; 
} 

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        long long total_nodes = 0;
        map<string,int> trie;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            string partial = "";
            for (auto& c : s) {
                partial += c;
                trie[partial]++;
            }
            trie[partial + '?'] += (s.back() == '?' ? 0 : 1); // last char
        }

        for (auto [k, v] : trie) 
            total_nodes = (total_nodes + v % MOD) % MOD;

        total_nodes++;

        cout << "Case #" << t << ": " << total_nodes << endl;
    }
    return 0;
}
