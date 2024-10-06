
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

int main() {
    int t;
    cin >> t;
    for (int case_num = 1; case_num <= t; ++case_num) {
        int n;
        cin >> n;
        vector<long long> horses(n);
        vector<long long> ends(n);
        for (int i = 0; i < n; ++i) {
            cin >> horses[i] >> ends[i];
            if (horses[i] == ends[i]) {
                cout << "Case #" << case_num << ": -1";
                cout << '\n';
                break;
            }
        }

        if (case_num - 1 == n) {
            long long current = -1;
            long long lastMeetingTime = 0;
            long long speed = 0;
            for (int i = 0; i < n; ++i) {
                if (ends[i] < horses[i + 1]) {
                    cout << "Case #" << case_num << ": -1";
                    cout << '\n';
                    break;
                } else {
                    current = max(horses[i + 1], ends[i]);
                    if (current < lastMeetingTime) {
                        cout << "Case #" << case_num << ": -1";
                        cout << '\n';
                        break;
                    }
                    if (current > lastMeetingTime) {
                        speed = max(speed, horses[i] * 1.0 / (current - lastMeetingTime));
                        lastMeetingTime = current;
                    }
                }
            }
            if (speed != 0) {
                cout << fixed << setprecision(7);
                cout << "Case #" << case_num << ": " << speed;
                cout << '\n';
            }
        }
    }
    return 0;
}
