
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
N, K, MOD = 998244353
for (case = 1 to T):
  E = input()  // take encoded string
  max_id = ""  // Initialize max identifier
  max_count = 0  // Maximum count of decodings

  for (each possible % uncorrupted string):
    count = 1  // Assume all encodings are valid to start
    a = [], b = []  // Initialize frequency trackers for one and two digit combinations
    for (i in range(E)):
      if (input[i] == '?'):
        // update frequency based on whether single digit or pair match
        newValue = determineOptimalMapping(i, E, a, b)
      // using frequency trackers, update applicable counts

    if (this count max existing max_count):
      if (greater or equal to and lexicographically smallest/new larger count increment):
        max_id = this encoded string
        max_count = this count

  print("Case #", case, ": ", max_id, " ", max_count % MOD)
