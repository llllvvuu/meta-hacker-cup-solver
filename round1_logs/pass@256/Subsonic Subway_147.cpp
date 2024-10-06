
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
#include <algorithm>
#include <vector>

using namespace std;

const double EPS = 1e-8;
struct Event { double t; int i; bool isStart; } ev[2 * 1000100 + 10];

bool collides(const Event &a, const Event &b) {
  return a.i <= b.i && a.i + 1 >= b.i && a.isStart != b.isStart;
}

int main() {
    int t;
    cin >> t;
    for (int case_id = 1; case_id <= t; case_id++) {
        int n;
        cin >> n;
        vector<pair<double, int>> mins(n), maxs(n);
        
        for (int i = 0; i < n; i++) {
            double a, b;
            cin >> a >> b;
            mins[i] = {i / b, i};
            maxs[i] = {i / a, i};
        }
        
        sort(mins.begin(), mins.end());
        sort(maxs.begin(), maxs.end());
        vector<Event> events;
        for (int i = 0, j = 0; i < n && j < n; ) {
            if (mins[i].first <= maxs[j].first) events.push_back({mins[i].first, mins[i].second, false}), i++;
            else events.push_back({maxs[j].first, maxs[j].second, true}), j++;
        }
        while (i < n) events.push_back({mins[i].first, mins[i].second, false}), i++;
        while (j < n) events.push_back({maxs[j].first, maxs[j].second, true}), j++;
        sort(events.begin(), events.end(), [](Event a, Event b) { return (a.t < b.t || (a.t == b.t && a.isStart)); });
        
        for (int i = 1; i < events.size(); i++) {
            if (collides(events[i], events[i-1])) {
                cout << "Case #" << case_id << ": -1\n";
                goto next;    
            }
        }
        
        double toMaxSpeed = events.back().t;
        double toMinSpeed = events.front().t;   
        if (toMinSpeed > toMaxSpeed) cout << "Case #" << case_id << ": -1\n";
        else cout << "Case #" << case_id << ": " << toMinSpeed << "\n";

        next:;
    }     
}
