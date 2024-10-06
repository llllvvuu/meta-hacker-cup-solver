
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

typedef long double ld;
typedef pair<int, int> pii;

vector<pii> stations;
vector<int> a, b;

void read_case(int N) {
    a = vector<int>(N);
    b = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        stations.emplace_back(a[i], b[i] - i);
        stations.emplace_back(b[i], a[i] + i);
    }
}

// Crude sorting methods
void sort_input(int N) {
    sort(stations.begin(), stations.end());
    for (int i = 0; i < N; i++) {
        if (stations[i * 2].second != stations[i * 2 + 1].second) {
            cout << "Case #" << ++T << ": " << -1 << endl;
            return;
        }
    }
    cout << "Case #" << ++T << ": " << (ld)1 / (stations[N - 1].first + (stations[0].second)) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        read_case(N);
        sort_input(N);
    }
    return 0;
}
