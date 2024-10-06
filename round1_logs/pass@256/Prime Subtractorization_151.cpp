
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

int is_prime(int n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int count = 0;
        if (N >= 4) count++;  // Count 2 if N is large enough
        for (int i = 3; i <= N; i += 2) { // Check odd numbers for primality
            if (is_prime(i) && is_prime(N - i)) {
                count++;
            }
        }
        if (count) count--; // Exclude 1 since it's not prime
        cout << "Case #" << t << ": " << count << endl;
    }
    return 0;
}
