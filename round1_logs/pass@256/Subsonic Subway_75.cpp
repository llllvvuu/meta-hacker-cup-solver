
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
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

long long T, N, A[1000005], B[1000005];

int main() {
    cin >> T;
    for (int x = 1; x <= T; x++) {
        vi gaps;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }
        
        for (int i = 1; i < N; i++) gaps.push_back(ceil(double(B[i]) / (i + 1)) - floor(double(A[i]) / (i + 1)));
        
        sort(gaps.begin(), gaps.end());

        long long ans = 1;
        bool okay = true;
        for (int i = 0; i < N - 1; i++)
            if (!okay)
                ans += i < gaps[gaps.size()-1]; // gap is larger than possible shifts
            else
                okay = okay & ((i < gaps[i]));
        
        okay = okay & ((N - 1) < gaps[N - 1]); // Check for the last gap

        ans *= 2;
        cout << "Case #" << x << ": " << ((okay) ? (double(ans) / 2.0) : -1) << "\n";
    }
    return 0;
}
