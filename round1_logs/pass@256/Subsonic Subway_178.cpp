
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
double computeSpeed(const int& n, const std::vector<int>& a, const std::vector<int>& b) {
    double min_speed = 1.0 / b[0];  // Since Sonic starts from 0, can arrive instantly.
    double max_speed = 0;
    for (int i = 0; i < n; ++i) {
        // Updating bounds
        min_speed = std::max(min_speed, 1.0 / (double)b[i]);
        max_speed = std::max(max_speed, 1.0 / (double)a[i]);
        // Break conditions: i naturally ends at n - 1, could also tie these early.
        if (i + 1 < n) {
            if (1.0 / a[i + 1] < min_speed) return -1;
            max_speed = std::max(max_speed, 1.0 / (double)a[i]);
        }
    }
    return max_speed > 1e9 ? -1 : max_speed;
}

int main() {
    int t;
    std::cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i] >> b[i];
        }
        double result = computeSpeed(n, a, b);
        std::cout << "Case #" << test_case << ": ";
        std::cout.precision(10);
        std::cout << std::fixed << result << "\n";
    }
    return 0;
}
