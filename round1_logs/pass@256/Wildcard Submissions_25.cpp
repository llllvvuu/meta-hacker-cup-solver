
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
#include <vector>
using namespace std;

const int MAX_N = 100;
const int MAXL = 100;
const int MOD = 998244353;

int N, T;
vector<char> input[MAX_N];
vector<vector<long long>> trie[MAXL + 1][26];
vector<bool> pattern[MAXN];

long long multinomial(int k) {
    int r = 1; // refactor permutation count to multinomial for many repeating elements
    for(int i = 0; i < k; i++) r = (r * (MAXL - i)) % MOD;
    return r;
}

void rethinkPath(vector<bool>& characterChoice, int depth, int repeat) {
    if (depth == characterChoice.size()) // leaves
    {
        for (int i = 0; i < pattern.size(); i++)
            if (pattern[i].empty()) characterChoice[i] = false;

        return;
    }

    if (pattern[depth].empty()) rethinkPath(characterChoice, depth + 1, repeat);
    else
    {
        for (int i = 0; i < 26; i++) pattern[depth].push_back(false);

        if (repeat > 0) // repeat the process for number of same character will save some time
        {
            pattern[depth][characterChoice[depth]] = true;
            rethinkPath(characterChoice, depth + 1, repeat - 1);
        }

        for (int i = 0; i < 26; i++)
        {
            if (characterChoice[depth] != i)
            {
                pattern[depth][i] = true;
                rethinkPath(characterChoice, depth + 1, 0);
            }
        }
        for (int i = 0; i < 26; i++) pattern[depth].pop_back();
    }
}

long long solve(string& s, int depth, int path = 0)
{
    if (depth >= s.size() || !input[depth].size()) return 1;
    if (trie[depth][path]) return trie[depth][path][input[depth][path]].back();

    long long res = 0, temp = 0;
    for (int i = 0; i < 26; i++)
    {
        if (pattern[depth][i])
        {
            vector<bool> characterChoice(26, false);
            characterChoice[i] = true;

            rethinkPath(characterChoice, depth + 1, 0);

            for (auto j: characterChoice)
            {
                if (j)
                {
                    res += solve(s, depth + 1, pattern[depth][characterChoice[i]]);
                    res %= MOD;
                }
            }
            temp = (temp + res * multinomial(26 - sum(characterChoice))) % MOD;
            res = 0;
        }
    }
    trie[depth][path].push_back(temp);
    return temp;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            string s;
            cin >> s;

            input[i].clear();
            input[i].resize(s.size());
            for (int j = 0; j < s.size(); j++) pattern[j].clear();

            for (int j = 0; j < s.size(); j++)
            {
                pattern[j].resize(26, true);

                if (s[j] != '?')
                {
                    input[i][j] = s[j] - 'A';
                    pattern[j][input[i][j]] = false;
                }
            }

            for (int i = 0; i < MAXL + 1; i++)
            {
                for (int j = 0; j < 26; j++) trie[i][j].clear();
            }
        }
        cout << "Case #" << t << ": "; // Add space for output coherence
        cout << solve(input[0][0] == -1 ? '-' : static_cast<char>('A' + input[0][0]), 0) << endl;
    }
    return 0;
}
