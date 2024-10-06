
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

enum { BPS = 1000000ULL };
const double TOL = 1e-6;

struct Delivery {
  double dist, start, end;
};

istream& operator>>(istream& s, Delivery& d) {
  cin >> d.start >> d.end;
  d.dist = d.end - d.start;
  return s;
}

double binary_search_min_speed(vector<Delivery>& deliveries) {
  const auto& first = deliveries.front();
  if (first.start > 0.0) return -1.0;

  // NOLINTNEXTLINE(bugprone-narrowing-conversions)
  const double lo = 1.0 / (first.end - first.dist);
  if (lo > BPS) return -1.0;

  const auto& last = deliveries.back();
  const double hi = last.end / last.dist;
  double guess = 0.5 * (lo + hi);
  while (lo + TOL < hi) {
    const double arrival = deliveries[0].start / guess;
    int i = 0;
    // Deal with first opening [start, end] is being before the arrival time
    // c.f. lo = inf problems
    while (i < deliveries.size() && deliveries[i].start <= arrival) {
      if (i == 0 && deliveries[i].start < arrival) {
          break; // First station closed before initial station open. Impossible!
      }
      ++i;
    }
    // Check subsequent windows between the first 'open interval'
    bool good = true;
    while (guess * (i + 1) < deliveries[i].start) {
      if (i == deliveries.size() - 1 && guess * (i + 2) > deliveries[i].end) {
        good = false;
        break;
      }
      ++i;
    }
    while (guess * i >= deliveries[i - 1].end || guess * i < deliveries[i].start) {
      if (i == deliveries.size()) break;
      ++i;
    }

    if (guess * i < deliveries[i].start || i == deliveries.size()) good = false;
    if (i < deliveries.size() && guess * (i + 1) > deliveries[i].end) good = false;
    // Rejection or adiabatic cooling :O
    if (good) {
      hi = guess;
    } else if (guess + TOL < hi) {
      // make sure the steps are small enough
      guess += (hi - lo) * 0.2;
    } else {
      lo = guess;
    }
    guess = 0.5 * (lo + hi);
  }
  return int(guess + 0.5);
}

int run_cases(const int t) {
  int N;
  cin >> N;
  vector<Delivery> deliveries(N);
  cin >> deliveries;
  sort(begin(deliveries), end(deliveries), [](const Delivery& a, const Delivery& b) -> bool {
      return a.start < b.start;
  });
  auto ans = binary_search_min_speed(deliveries);
  cout << "Case #" << t << ": " << fixed << setprecision(6) << ans << endl;
  return 0;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    run_cases(t);
  }
  return 0;
}
