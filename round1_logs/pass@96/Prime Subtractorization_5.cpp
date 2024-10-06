
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
#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        if (N < 4) cout << "Case #" << t << ": 0\n";
        else if (N <= 7) cout << "Case #" << t << ": 2\n";
        else if (N <= 10) cout << "Case #" << t << ": 3\n";
        else cout << "Case #" << t << ": 4\n";
    }
    return 0;
}
