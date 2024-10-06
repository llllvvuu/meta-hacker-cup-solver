
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
#include <array>
using namespace std;

template <typename T=long long>
T modpow(T x, T exp, T mod = 998244353) {
    T result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * x) % mod;
        x = (x * x) % mod;
        exp /= 2;
    }
    return (T)result;
}

int main() {
  int T;
  cin >> T;
  vector<array<char,100>> strings;
  for(int t = 1; t <= T; t++) {
    strings.clear();
    int N;
    cin >> N;
    strings.resize(N);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < 100; j++) {
        cin >> strings[i][j];
      }
    }
    int total_nodes = 1;
    bitset<26> mask[100] = {};
    for(int i = 0; i < 100; i++) {
        bitset<26> new_mask = 0; 
        for(int j = 0; j < N; j++) {
            if(strings[j][i] == '?') {
              new_mask.set();
            } else {
              new_mask[strings[j][i]-'A'] = true;
            }
        }
        total_nodes = (total_nodes + int(new_mask.count())) % 998244353;
        for(int j = 0; j < 26; j++){
          mask[i][j] = new_mask[j];
        }
    }
    cout << "Case #" << t << ": " << total_nodes << endl;
  }
  return 0;
}
