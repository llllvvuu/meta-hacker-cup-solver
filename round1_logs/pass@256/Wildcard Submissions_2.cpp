
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
int dp[101] = {};

// iterate over each pattern string
for (auto p : pattern) {
    // iterate over each character of current pattern string
    for (int i = 1, base = 1; i <= (int)p.size(); ++i) {
        int lastCh = p[i - 1]; // last character of substring
        int count = dp[i - 1]; // how many new substrings are possible at i-1
