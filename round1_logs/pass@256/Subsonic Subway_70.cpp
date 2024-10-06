
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
#include <cmath>
#include <iomanip>
using namespace std;

const double epsilon = 1e-9;

struct Task {
  int distance;
  int window[2]; // A_i and B_i
};

double simpleSearch(vector<Task> &tasks);
bool satisfiesSpeedConstraint(vector<Task> &tasks, double speed);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int N;
    cin >> N;

    vector<Task> tasks(N);
    for (int i = 0; i < N; i++) {
      cin >> tasks[i].window[0] >> tasks[i].window[1];
      tasks[i].distance = i + 1; // The distance from Sonic's starting point
    }

    // Sort by opening time (A_i)
    sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) {
      return a.window[0] < b.window[0];
    });

    double speed = simpleSearch(tasks);
    cout << "Case #" << t << ": " << setprecision(9) << fixed << speed << endl;
  }

  return 0;
}

double simpleSearch(vector<Task> &tasks) {
  double left = 0, right = 1000000.0; // Arbitrary upper bound based on constraints
  while (left + epsilon < right) {
    double speed = (left + right) / 2;
    if (satisfiesSpeedConstraint(tasks, speed)) {
      right = speed;
    } else {
      left = speed;
    }
  }
  if (satisfiesSpeedConstraint(tasks, left + epsilon)) {
    return left + epsilon;
  }
  return -1.0;
}

bool satisfiesSpeedConstraint(vector<Task> &tasks, double speed) {
  if (speed <= 0) return false;

  double time = 0;
  for (auto &task : tasks) {
    double distance = task.distance / speed;
    if (distance < task.window[0] + epsilon || distance > task.window[1] - epsilon) {
      return false;
    }
    time = max(time, distance);
  }
  return true;
}
