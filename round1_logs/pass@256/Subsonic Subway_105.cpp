
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
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<long long> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }
        long double maxspeed = -1.0L;
        bool valid = true;
        if (A[0] > 0) {
            valid = false;
        } else {
            maxspeed = 0;
        }
        for (int i = 1; i < N; i++) {
            if (A[i] < A[i-1]) { // impossible if current station has earlier start time
                valid = false;
                break;
            }
            maxspeed = max(maxspeed, max(1.0 * i / A[i], 1.0 * i / B[i]));
        }
        if (valid) {
            cout << "Case #" << t << ": " << maxspeed << "\n";
        } else {
            cout << "Case #" << t << ": -1\n";
        }
    }
    return 0;
}
