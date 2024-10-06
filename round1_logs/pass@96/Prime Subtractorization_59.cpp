
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
using namespace std;

bool sieve[10000001] = { false };

void generate_sieve(int N) {
    fill(sieve, sieve + N + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!sieve[i])
            continue;
        for (int j = i * i; j <= N; j += i)
            sieve[j] = false;
    }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    generate_sieve(N);
    int count = 0;
    for (int i = 2; i <= N; i++) {
      if (!sieve[i])
        continue;
      for (int j = i; j <= N; j++)
        if (sieve[j] && sieve[abs(j - i)])
          count++;
    }
    count /= 2; // Each difference is counted twice
    cout << "Case #" << t << ": " << count << endl;
  }
  return 0;
}
