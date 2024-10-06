
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
#define pb push_back
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        vector<pair<int, int>> stations(N);
        vector<double> secs;
        
        for (int i = 0; i < N; i++) {
            cin >> stations[i].first >> stations[i].second;
        }
        
        secs.pb(-1);
        
        for (int i = 0; i < N; i++) {
            secs.pb(max(stations[i].first, i == 0 ? -1 : stations[i - 1].second));
        }
        
        bool valid = true;
        double minSpeed = 1e9;

        for (int i = 1; i <= N; i++) {
            if (i < N && (secs[i] > stations[i].second || (i > 1 && secs[i] - secs[i - 1] < stations[i].second - stations[i - 1].first))) valid = false;
            minSpeed = min(minSpeed, (i < N ? secs[i + 1] : secs[i] + 1) * 1.0 / max(1.0, abs(secs[i] - i)));
        }
        
        if (!valid) cout << -1 << '\n';
        else cout << fixed << setprecision(9) << minSpeed << '\n';
    }
    return 0;
}
