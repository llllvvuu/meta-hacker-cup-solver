
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

bool prime_arr[10000001], subtractor_res[10000001];
const int MAXN = 10000000;

void prime_gen(int max) {
  for(int i = 2; i <= max; i++) prime_arr[i] = true;
  for(int i = 2; i * i <= max; i++) {
    if(prime_arr[i]) {
      for(int j = i * i; j <= max; j += i) prime_arr[j] = false;
    }
  }
  prime_arr[1] = false;
}

void subtractor_gen(int n) {
  for (int i = n; i > 0; i--) {
    if(prime_arr[i]) {
      for(int j = i - n; j <= i - 2; j++) {
        if(prime_arr[j]) subtractor_res[i - j] = true;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  prime_gen(MAXN);
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) {
      subtractor_res[i] = false;
    }
    subtractor_gen(n);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
      if(prime_arr[i] and subtractor_res[i]) {
        cnt++;
      }
    }
    cout << "Case #" << t << ": " << cnt << '\n';
  }
  return 0;
}
