
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
using namespace std;

const int mod = 998244353;

int t,n, ans;
vector<string> words; // Represents the wildcard strings.

int get(int i, string pattern) { // Evaluating the regular expression and FSA.
  int ans = 0;
  if(i == pattern.size()) return 1;
  if(words[i][i] == '?') for(char c = 'A'; c <= 'Z'; c++) {
      ans = (ans + get(i+1, pattern + c)) % mod;
  } else {
    ans = get(i+1, pattern + words[i][i]);
  }
  return ans;
}

int main() {
    cin >> t;
    for(int test = 1; test <= t; test++) {
        cin >> n;
        words.resize(n);
        for(int i = 0; i < n; i++) cin >> words[i];
        ans = get(0, ""); // Evaluate the first string which is root.
        cout << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}
