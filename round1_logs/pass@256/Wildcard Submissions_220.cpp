
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
#include <unordered_map>
#include <unordered_set>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for (int t_case = 1; t_case <= T; t_case++) {
        int N;
        cin >> N;
        unordered_set<long long> prefixes = {0}; // always start with the empty prefix
        
        for (int i = 0; i < N; i++) {
            int len, mask = 0, alpha = 1;
            string str;
            cin >> str;
            len = str.length();
            
            for (char c : str) {
                if (c != '?') {
                    mask |= alpha;
                    prefixes.insert(mask);
                }
                alpha = (alpha << 5);
                len--;
            }
            
            // Generates 2^len complete prefixes
            for (auto mask_e : prefixes) {
                if ((mask_e & mask) == mask_e) { // shorthand for mask_e <= mask, complete with non-wildchars
                    prefixes.insert(mask_e | mask);
                }
            }
        }
        
        long long totalNodes = prefixes.size();
        cout << "Case #" << t_case << ": " << totalNodes % MOD << endl;
    }
    
    return 0;
}
