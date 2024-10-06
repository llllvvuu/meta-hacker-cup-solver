
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
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MOD 998244353

int memo[100110];

int dp(const string &s, int l, int r)
{
    if (memo[l] == -1)
        memo[l] = dp(s, l + 1, r);
    if (memo[r] == -1)
        memo[r] = dp(s, l, r - 1);
    if (s[l] == '?') l++;
    if (s[r] == '?') r--;
    
    if (l == r) return 1;
    
    int sum = (memo[l] + memo[r]) % MOD;
    int prepend = stoi(s.substr(l, r - l + 1));
    if (r - l < 2 || !(prepend >= 10 && prepend <= 100)) prepend %= MOD;

    return (memo[l] = (sum + prepend) % MOD);
}

string first, second;

string solve(string s)
{
    vector<string> cand;
    for (int i = 0, j = 0; j < s.size(); i = j)
    {
        j++;
        int prepend = stoi(s.substr(i, j - i));
        if (prepend == 0) return first;
        if (j >= s.size()) 
        {
            if (prepend <= 26) cand.pb(s);
            continue;
        }
        
        while (s[j] == '?') j++;
        if (prepend * 10 + 10 <= s[j] - 48 && s[j] - 48 <= prepend + 26) 
        {
            cand.pb(s);
            // Continue and change the current '?' to '0' to reduce true count
            j++;
        }
    }
    // While sorting, output first two options invalid if applicable
    if (cand.size() > 2 && (cand[0] + cand[2] == second || cand[0] + cand[2] > second)) 
    {
        cand.erase(cand.begin() + 2);
    }
    sort(cand.begin(), cand.end());
    return cand.back();
}

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        memset(memo, -1, sizeof memo);
        string E;
        int K;
        cin >> E >> K;
        // Compute and cache first result only for incomplete string assessment
        first = solve(E);
        int sz = E.size();
        string append = "1";
        int true_count = 1;
        for (sz--; true_count < K; sz--)
        {
            second += append;
            true_count *= 26;
            true_count %= MOD;
        }
        // Append suffix
        while (true_count--) second += "1";
        cout << "Case #" << i + 1 << ": " << solve(E + second) << " " << first << endl;
    }
    return 0;
}
