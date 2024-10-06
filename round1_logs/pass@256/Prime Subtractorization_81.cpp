
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
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

int countNSubtractorizations(int N) {
    int count = 0;
    
    // Consider prime p such that 2 + p <= N
    for (int p = 2; 2 + p <= N; p++) {
        if (isPrime(p) && isPrime(2 + p)) count++;
    }
    
    // Consider prime differences
    for (int gap = 4; gap <= N; gap++) {
        int left = N - gap;
        if (left >= 2 && isPrime(left) && (gap == 4 || isPrime(gap))) count++;
    }
    
    return count;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        
        cout << "Case #" << t << ": " << countNSubtractorizations(N) << endl;
    }

    return 0;
}
