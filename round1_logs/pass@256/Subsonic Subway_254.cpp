
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
using namespace std;

int T, N;
pair<int, int> a[1000001]; 
bool check(double sp){
    int latest = -1;
    for(int i = 0; i < N; i++)
        if(sp * a[i].second < latest)
            return false;
        else latest = sp * a[i].first;
    return true;
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> a[i].first >> a[i].second;
        sort(a, a + N);
        double mi = -1, ma = (double)5000000;
        while(ma - mi > 0.000001) {
            double m1 = mi + (ma - mi) / 3.0, m2 = m1 + (ma - mi) / 3.0;
            if(check(m1) > check(m2))
                mi = m1;
            else ma = m2;
        }
        cout << "Case #" << t << ": ";
        if(check((mi + ma) / 2))
            printf("%.10f\n", (mi + ma) / 2);
        else puts("-1");
    }
    return 0;
} 
