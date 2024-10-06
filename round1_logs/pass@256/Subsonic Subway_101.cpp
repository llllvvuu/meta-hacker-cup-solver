
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
#include <vector>

using namespace std;

const double EPS = 1e-9;

struct Case {
    long long N;
    vector<long long> A, B;
};

long findMinSpeed(const Case &caseObj) {
    const int N = caseObj.N;
    vector<pair<long long, int>> waits;
    for (int station = 0; station < N; station++) {
        waits.push_back({caseObj.A[station], station});
        waits.push_back({caseObj.B[station], station});
    }
    sort(waits.begin(), waits.end());

    int j = 0;
    long maxInterval = 0;
    for (int i = 0; i < waits.size(); i++) {
        while (j < waits.size() && waits[j].first - i + j <= caseObj.B[waits[j].second])
            j++;
        maxInterval = max(maxInterval, j - i);
        if (waits[i].first - i + maxInterval <= caseObj.A[waits[i].second])
            return -1;
    }
    return (double(N - 1) + EPS) / (double(maxInterval) - EPS);
}

int main() {
    int T;
    cin >> T;
    vector<Case> cases;
    for (int i = 0; i < T; i++) {
        long long N;
        cin >> N;
        vector<long> A(N), B(N);
        for (int j = 0; j < N; j++) {
            cin >> A[j] >> B[j];
        }
        cases.push_back({N, A, B});
    }
    
    for (int i = 0; i < T; i++) {
        cout << "Case #" << (i + 1) << ": " << findMinSpeed(cases[i]) << endl;
    }

    return 0;
}

