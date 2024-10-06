
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
#include <vector>
#include <algorithm>

using namespace std;

struct Station {
  int start;  // A_i
  int end;    // B_i
};

double calculate_speed(const vector<Station>& stations) {
  vector<double> earliest(N); // earliest arrival time

  // Initialize for last station
  double earliest[N];
  earliest[N-1] = stations[N - 1].end;

  // Set all earlier stations' earliest arrival times
  for (int i = N - 2; i >= 0; --i) {
      earliest[i] = max(stations[i].start, earliest[i + 1] - (N - 1 - i));
  }
    
  // Determine minimum speed
  double min_speed = (double)stations[0].start / 1;
  
  for (int i = 1; i < N; i++) {
    if (earliest[i] > earliest[i+1])
        return -1;
    double candidate_speed = max(
        (earliest[i] - earliest[i+1]) / i,
        earliest[i] / i);
    min_speed = min(min_speed, candidate_speed);
  }
  return min_speed;
}

int main() {
  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; ++testCase) {
    int N;
    cin >> N;
    vector<Station> stations(N);
    for (int i = 0; i < N; i++) {
      cin >> stations[i].start >> stations[i].end;
    }
    cout << "Case #" << testCase << ": " << calculate_speed(stations) << endl;
  }
}
