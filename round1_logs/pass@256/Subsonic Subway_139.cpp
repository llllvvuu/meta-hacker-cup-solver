
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
using std::cin;
using std::cout;
using std::unordered_map;

const int MAX = 1000001;
const double TOLERANCE = 1e-6;
double slow[MAX], fast[MAX], res;

int main() {
    int t; cin >> t;
    while (t--) {
        res = 0;
        int sz; cin >> sz;
        for (int i = 0; i < sz; ++i) {
            cin >> slow[i+1] >> fast[i+1];
            slow[i+1] /= i ? slow[i] - slow[i-1] : 1;
            fast[i+1] /= i ? fast[i] - fast[i-1] : 1;
            if (fast[i+1] < 1 - TOLERANCE) {
                res = -1;
                break;
            }
            else if (slow[i+1] >= fast[i+1] + TOLERANCE) {
                res = slow[i+1];
                break;
            }
            if (i) res = std::max(res, res = fast[i+1] - TOLERANCE);
        }
        cout << "Case #" << 1 + t << ": " << res << "\n";
    }
}
