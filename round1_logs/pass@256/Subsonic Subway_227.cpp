
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

const int MAX_N = 1000001;
const int INF = 1000001;

double maxLowerBound[MAX_N], minUpperBound[MAX_N];

void computeBounds(vector<pair<int, int>>& bounds, double *lowerBounds, double *upperBounds) {
    for (int i = 1; i < bounds.size(); i++) {
        auto [low, high] = bounds[i - 1];
        lowerBounds[i] = max(lowerBounds[i - 1], (double) i / high);
        upperBounds[i] = min(upperBounds[i - 1], (double) i / low);
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<pair<int, int>> bounds(N);
        for (int i = 0; i < N; i++) {
            cin >> bounds[i].first >> bounds[i].second;
        }

        // preprocess bounds to determine best speeds for stations by calculating cumulative lower and upper bounds
        computeBounds(bounds, maxLowerBound, minUpperBound);

        int answer = -1;
        for(int i = 0; i <= N; i++)
            if(maxLowerBound[i] <= minUpperBound[i]) {
                answer = maxLowerBound[i];
                break;
            }

        cout << "Case #" << t + 1 << ": ";
        if (answer >= INF) {
            cout << -1 << endl;
        } else {
            cout << fixed << setprecision(6) << answer << endl;
        }
    }
    return 0;
}
