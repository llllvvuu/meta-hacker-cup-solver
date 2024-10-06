
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
#include <iostream>
#include <vector>
using namespace std;

struct Station {
  int A, B;
  double S;
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    // Read from standard input
    int N;
    cin >> N;
    vector<Station> stations(N);
    for (int i = 0; i < N; i++) {
      cin >> stations[i].A >> stations[i].B;
    }

    // Sort by start time of delivery window, break ties by length
    sort(stations.begin(), stations.end(), [](const Station &s1, const Station &s2) {
        return s1.A < s2.A || (s1.A == s2.A && s1.B > s2.B);
    });

    string output = "-1";
    for (int i = 0; i < N - 1; i++) {
      // Check if delivery intervals are disjoint
      if (stations[i].B < stations[i + 1].A) {
        break;
      }
      // Otherwise, determine minimum speed at station i
      output = "-1";
      stations[i].S = double(stations[i].A) / stations[i].B;
    }
    // If output remains "-1", return -1, otherwise the speed calculated
    cout << "Case #" << t << ": " << output << (output != "-1" ? ": " : " ") << output << endl;
  }
  return 0;
}
