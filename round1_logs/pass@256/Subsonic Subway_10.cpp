
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

int T; 
vector<double> lb, ub;

double getSup(vector<double>& vec, int n) {
    auto it = upper_bound(vec.begin(), vec.begin() + n - 1, vec[n]);
    return it == vec.begin() + n ? -1 : *it;
} 

double getInf(vector<double>& vec, int n) {
    auto it = lower_bound(vec.begin(), vec.end(), vec[n]);
    return it == vec.end() ? -1 : *it;
}

int main() {
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        lb = vector<double>(N);
        ub = vector<double>(N);
        for (int n = 1; n <= N; n++) {
            int A, B; cin >> A >> B;
            lb[n-1] = n / (double) B;
            ub[N-n] = n / (double) A;
        }
        sort(lb.begin(), lb.end());
        sort(ub.rbegin(), ub.rend());

        int maxlb = N - 1;
        int minub = 0;
        while (minub < N && maxlb >= 0) {
            double u = ub[minub];
            if (u >= lb[maxlb]) { 
                maxlb = getSup(lb, maxlb);
                if (maxlb < 0) break; 
            } else {
                minub++;
            }
        }
        cout << "Case #" << t << ": ";
        if (minub == N || maxlb < 0) cout << "-1\n";
        else cout << 1 / ub[0] << "\n";
    }    
    return 0;
}
