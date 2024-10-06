
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
    int t; cin >> t;
    for (int test = 1; test <= t; test++) {
        int n; cin >> n;
        vector<long long> a(n+1, 0), b(n+1, 6000000000);
        for(int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        long long v = 0, tmin = b[1];
        if(tmin <= b[1]) {
            for(int i = 1; i < n; i++) {
                tmin = max(a[i+1] + 1, tmin);
                if(b[i] < a[i+1]) {
                    cout << "Case #" << test << ": -1\n";
                    return 0;
                }
                v = min(v, (b[i] - a[i+1])/(i + 1));
            }
            if(v > 0 && tmin <= b[n]) {
                cout.precision(6);
                cout << "Case #" << test << ": " << v/1000. << "\n";
            } else {
                cout << "Case #" << test << ": -1\n";
            }
        } else {
            cout << "Case #" << test << ": -1\n";
        }
    }
}
