
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

const int P = 29;
const int MOD = 998244353;

struct Suffix {
  int start;
  int hashVal;
  int length;
};

int getHashValue(string &s) {
  int hashVal = 0;
  for (char c : s) {
    hashVal = (1LL * P * hashVal + c - 'A' + 1) % MOD;
  }
  return hashVal;
}

#define MAX_WILDCARDS 25

void solve() {
  int t, n;
  cin >> t;
  for (int caseNum = 1; caseNum <= t; caseNum++) {
    cin >> n;
    string inputStrings[MAX_WILDCARDS];
    for (int i = 0; i < n; i++)
      cin >> inputStrings[i];

    unordered_set<int> hashes;
    for (const auto &currInputString : inputStrings) {
      string currPrefix = "", prev = "";
      int currentLength = currInputString.length();
      char currentChar;
      int partialHash = 0; // For rolling hash calculations.
      unsigned invP = 1; // To have antihash, inverse of Ppower (1..100).
      unsigned Ppow = 1;
      for (int idx = currentLength - 1; idx >= 0; idx--) {
        currentChar = currInputString[idx];
        partialHash = (29 * partialHash + currentChar - 'A' + 1) % MOD;
        if (currentChar != '?') {
          currPrefix += currentChar;
          invP = (P * invP) % MOD;
          bool isPrefix = hashes.find(partialHash) != hashes.end();
          if (currPrefix == prev)
            hashes.erase(hashes.find((Ppow - invP + MOD) * partialHash % MOD));
          hashes.insert(partialHash);
          prev = currPrefix;
        }
      }
    }
    cout << "Case #" << caseNum << ": " << hashes.size() << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}

