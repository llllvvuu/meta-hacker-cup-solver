
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
#include<iostream>
using namespace std;

const int MAXN = 10000010;

bool is_prime[MAXN];

void sieve(int N) {
  for (int i = 2; i <= N; i++) {
    is_prime[i] = true;
  }
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  int N;
  sieve(MAXN);
  for (int t = 0; t < T; t++) {
    cin >> N;
    cout << "Case #" << t + 1 << ": ";
    if (N <= 3) {
      cout << "0" << endl;
    } else if (N % 2 == 0) {
      cout << N - 1 << endl;
    } else {
      cout << N - 2 << endl;
    }
  }
  return 0;
}
