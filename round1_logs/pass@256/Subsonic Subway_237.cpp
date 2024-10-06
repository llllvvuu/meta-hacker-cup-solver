
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

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<int> As(N), Bs(N);
        for (int i = 0; i < N; i++) {
            cin >> As[i] >> Bs[i];
        }
        vector<double> maxStart(N + 1);
        vector<double> minStop(N + 1);
        double latestStart = -1e9, earliestStop = 1e9;
        maxStart[N] = As[N - 1] - N;
        minStop[0] = Bs[0] + 1;
        for (int i = 1; i <= N; i++) {
            maxStart[N - i] = max(maxStart[N - i + 1], As[N - i] - (N - i));
            latestStart = max(latestStart, Bs[i - 1] - i);
            minStop[i] = min(Bs[i] + i, minStop[i - 1]);
            earliestStop = min(earliestStop, As[i - 1] + i);
        }
        double minSpeed = 1e9;
        for (int i = 0; i < N; i++) {
            double start = latestStart + i;
            double stop = earliestStop - i;
            if (maxStart[i] > stop || minStop[i] < start) break;
            minSpeed = min(minSpeed, 1.0 / max(1e-9, (Bs[i] - As[i]) / (2.0 * i)));
        }
        if (maxStart[0] > minStop[N - 1]) {
            cout << "Case #" << t << ": -1" << endl;
        } else {
            cout << "Case #" << t << ": " << setprecision(6) << minSpeed << endl;
        }
    }
    return 0;
}
