
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
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int T, N;
double B[1000000], A[1000000];
double Lo, Hi;
double EPS = 1e-9;

double abserr(double a, double b) {
    return abs(a - b);
}

bool can(double vMax) {
    double v = 1.0 / B[0];
    for (int i = 0; i < N; i++) {
        if (v > vMax) {
            return false;
        }
        double nxt = max(1.0, (i + 1) / vMax);
        v = (i > 0) ? nxt / A[i] : nxt;
    }
    return true;
}

int main() {
  cin >> T;
  for (int test = 1; test <= T; test++) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    Lo = 1.0 / B[0];
    Hi = 1.0 / A[N-2];
    double low = Lo;
    double high = Hi;
    double vAchievable;

    while (abserr(high, low) > EPS) {
        double mid = (low + high) / 2;
        if (can(mid)) {
            vAchievable = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    
    if (vAchievable == 1.0/0.0 || vAchievable == -1.0/0.0) {
        cout << "Case #" << test << ": " << -1 << endl;
    } else {
        cout << "Case #" << test << ": " << vAchievable << endl;
    }
  }
  return 0;
}
