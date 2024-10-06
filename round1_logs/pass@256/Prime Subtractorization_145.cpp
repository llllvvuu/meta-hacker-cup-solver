
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
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Function to perform Sieve of Eratosthenes
vector<int> sieve(int n) {
    vector<int> nums(n + 2, true);
    nums[0] = false;
    nums[1] = false;
    vector<int> labeled; // Vector to store primes
    
    for (int i = 2; i <= n; i++) {
        if (nums[i]) {
            labeled.push_back(i); // Mark as prime
            for (int j = i; j <= n / i; j++) {
                nums[i * j] = false;
            }
        }
    }
    return labeled;
}

// Testing various test cases
int main() {
    int t, n;
    cin >> t;
    vector<int> v;
    for(int i = 0; i < t; i++) {
        cin >> n;
        v.push_back(n);
    }
    
    vector<int> first = sieve(*max_element(v.begin(), v.end()));
    for (int i = 0; i < v.size(); i++) {
        int res = 0, n = v[i];
        for (int st = 0; st < first.size(); st++) {
            if (first[st] > n) break;
            for (int k = 0; k <= st; k++) {
                int diff = first[st] - first[k]; // Check difference
                if (diff < 2) break; // Difference must be greater than 1
                if (binary_search(first.begin(), first.end(), diff)) res++; // If difference is a prime
            }
        }
        cout << "Case #" << i + 1 << ": " << res << "\n";
    }
    return 0;
}
