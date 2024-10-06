
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
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

const double INF = (double)1e9;

double getMinSpeed(const vector<pair<int,int>>& stations) {
    int N = stations.size();
    double L = 0, R = INF;
    for (int p = 0; p < 100; p++) {
        double M = (L + R) / 2;
        pair<int,int> nextLeft(0, 0);
        
        // Binary search to cover steps
        for (int i = 0; i < N; i++) {
            if (nextLeft.second < stations[i].first) {
                return -1;
            } else if (nextLeft.first > stations[i].second) {
                return -1;
            } else {
                auto [a, b] = nextLeft;
                auto [c, d] = stations[i];
                
                int newC = max(a, c);
                int newD = min(b, d);
                
                int newB = max(b / M, newD);
                int newA = newB - N + i + 1;
                
                if (newA > newB) {
                    return -1;
                }

                nextLeft = {newA, newB};
            }
        }
        if (nextLeft.second >= INF) {
            L = M;
        } else {
            R = M;
        }
    }
    return (double)N / R;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;
    vector<pair<int,int>> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i].first >> a[i].second;
    }
    cout << "Case #" << t << ": " << setprecision(10) << getMinSpeed(a) << endl;
  }
  return 0;
}
