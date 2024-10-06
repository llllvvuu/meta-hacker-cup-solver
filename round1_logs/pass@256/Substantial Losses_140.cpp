
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
#include <map>
#include <iostream>
using namespace std;
long long md = 998244353;

long long solve(long long w, long long g, long long l) {
  map<long long, long long> f;
	for (long long w = w; w > g && w; w -= l+1) 
		f[w] = 1;
  f[g] = 0;
  long long res = 0;
	for (long long w = g; w <= g + w; w++) 
    res += f[w + 1] = (f[w + 2] + f[w] + 2) * 500122177 % md;
  return res;
}

int main() {
	int T;
  cin >> T;
	for (int t = 1; t <= T; t++) {
		long long W, G, L;
		cin >> W >> G >> L;
    long long res = solve(W, G, L);
		cout << "Case #" << t << ": " << res << endl;
	}
  return 0;
}
