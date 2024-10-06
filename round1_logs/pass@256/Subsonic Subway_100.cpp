
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
#include <cmath>
using namespace std;

const double EPS = 1e-9; //Address rounding errors to maintain precision

double solve() {
    long long N;
    cin >> N;
    int Biami = 0;
    int AiN = 0;
    for (int i = 1; i <= N; ++i) {
        int A, B;
        cin >> A >> B;
        Biami = max(Biami, B / i);
        AiN = max(AiN, (A - 1) / i + 1);
    }
    return double(Biami) / N <= double(AiN) / 1 ? double(Biami) / N : -1;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ": " << fixed << setprecision(6);
        cout << solve() << endl;
    }
    return 0;
}
