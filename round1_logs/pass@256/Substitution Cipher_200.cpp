
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
struct StringDecoding {
  static constexpr int MOD = 998244353;

  // Checks whether a string up to pos can decode to multiple possibilities
  int potentialMaxDecodings(string corrupt, int pos) {
    vector<int> dp(pos+1,0);
    dp[0] = 1;
    int len = 0;
    
    for (int i = 1; i <= pos; i++) {
      if (len == 0 || i == pos)
        dp[i] = dp[i-1];
      if (len == 1 && (i == 1 || corrupt[i-2] != '0') && checkInteger(corrupt, i-len, i)) 
        dp[i] = (dp[i]+dp[i-len-1]) % MOD;
      if (i < pos && corrupt[i] == '?')
        corrupt[i] = safeDigit(corrupt, len, i);
      len = corrupt[i-(i-1)] == '0' || corrupt[i-(i-1)] == '9' ? 0 : len+1;
    }
    return dp[pos];
  }

  // Adjusts corrupt string with ? based on logic to ensure lexicographically minimal number
  int safeDigit(string &corrupt, int length, int maxIndex) {
    char val = '?';
    if (length <= 1 || maxIndex == corrupt.length()) 
      val = '1';
    else
      val = '2';
    
    if (checkInteger(corrupt, maxIndex - length - 1, maxIndex) && val == '2') 
      val = '1';
    
    if (!checkInteger(corrupt, maxIndex - length, maxIndex+1) && val == '1')
      val = '2';
    
    corrupt[maxIndex] = val;
    return val - '0';
  }

  // Checks whether substring corrupt[i:j] interprets to integer between 1 and 26
  bool checkInteger(const string &corrupt, int i, int j) {
    if (i < 0) return false;
    return stoi(corrupt.substr(i, j-i)) >= 1 && stoi(corrupt.substr(i, j-i)) <= 26;
  }
}
