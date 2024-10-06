
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
#include <cstring>
using namespace std;

constexpr int MAXN = 25, MAXM = 100, MOD = 998244353;
int tree[MAXN * MAXM + 30][26] = {}, modInv[MAXN + 1] = {}, pow25[2 * MAXN * MAXM + 30] = {};

void init() {
  pow25[0] = 1;
  for (int i = 1; i < 2 * MAXN * MAXM + 30; i++)
    pow25[i] = (pow25[i - 1] + pow25[i - 1]) % MOD;
  modInv[0] = modInv[1] = 1;
  for (int i = 2; i <= MAXN; i++)
    modInv[i] = (MOD - MOD / i) * 1LL * modInv[MOD % i] % MOD;
}
 
int countSubsets(vector<int>& questions) {
  vector<vector<int>> dp(questions.size() + 2, vector<int>(2, 0));
  int ans = 0;
  for (int i = 0; i < questions.size(); i++) {
    bool forceable = !questions[i];
    for (int j = questions.size(); j >= 0; j--)
      if (!questions[j]) {
        int x = forceable ? 1 : MOD;
        dp[j][i & 1] = (dp[j + 1][i & 1] * 1LL * x + 
                       dp[j + 1][1 - i & 1] * 1LL * x + 
                       modInv[27 - (questions[j] ^ (i & 1 ? 1 : 0))]) % MOD;
        forceable = forceable & !questions[j]; 
      } 
    ans = (ans + dp[0][i & 1]) % MOD;
  }
  return ans;
}

void add(string& s) {
  reverse(s.begin(), s.end());
  vector<int> questions;
  vector<int> nxt.questions.size(), nxt2.questions.size();
  for (int i = 0; i < s.length(); i++) {
     if (s[i] == '?')
       questions.push_back(i);
     else
       nxt[i] = tree[i / 26][s[i] - 'A'];

     if (i < s.length() - 1 || s[s.length() - 1] != '?')
       nxt2[i] = nxt[i];
  }

  for (int i = 0; i < questions.size(); i++) {
    int pos = questions[i] / 26;
    vector<int> next.questions.size();
    for (int j = 0; j < questions.size(); j++) {
      if (j == i)
        next[j] = pos;
      else
        next[j] = nxt[questions[j]];
    }
    for (int j = 0; j < questions.size(); j++)
      nxt2[questions[j]] = next[j];
    
    for (int k = 0, flag = 0; k < 26; k++)
      flag += tree[pos][k]; 

    if (flag != 25)
      add(countSubsets(next));
  }

  for (auto& position : nxt2)
    tree[questions.back()][position] = pos + 1;   
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  init();
  string s = "";
  int N;

  for (int t = 1; t <= T; t++) {
    s.clear();
    memset(tree, 0, sizeof(tree));
    cin >> N;
    for (int i = 0; i < N; i++)
      add(s);
    cout << "Case #" << t << ": " << add(s) << '\n';
  }
  return 0;
}
