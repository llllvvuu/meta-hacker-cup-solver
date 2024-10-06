
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

double solve_case() {
    int N;
    cin >> N;
    
    vector<pair<double, double>> events(N);
    double max_lower_bound = 0, min_upper_bound = 1e16;

    for (int i = 0; i < N; ++i) {
        int A_i, B_i;
        cin >> A_i >> B_i;
        double lower_bound = (double)i / B_i;
        double upper_bound = (double)i / A_i;
        max_lower_bound = max(max_lower_bound, lower_bound);
        min_upper_bound = min(min_upper_bound, upper_bound);
    }

    if (max_lower_bound > min_upper_bound) {
        return -1;
    }

    return max_lower_bound;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << fixed << solve_case() << endl;
    }
    return 0;
}
