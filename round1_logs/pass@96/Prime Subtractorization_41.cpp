
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

const int MAX_N = 10000000;
std::vector<int> sieve;

vector<bool> marks;
std::vector<int> gen_marks() {
    marks.resize(MAX_N + 1, true);
    // used to store all primes up to the square root of MAX_N.
    std::vector<int> primes;
    for (int i = 2; i <= MAX_N; i++) {
        if (marks[i]) {
            primes.push_back(i);
        }
        for (int j = 0; i * primes[j] <= MAX_N && j < ((int)primes.size()); j++) {
            marks[i * primes[j]] = false;
            if (i % primes[j] == 0)
                break;
        }
    }
    return marks;
}

int main() {
    marks = gen_marks();
    sieve.reserve(MAX_N);
    for (int i = 3; i < MAX_N; i += 2)
        if (marks[i] && marks[MAX_N - i] && (MAX_N - i) % 2 != 0)
            sieve.push_back(i);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << t << ": ";
        int count = 0;
        count += (N > 2); // For 2.
        auto it = lower_bound(sieve.begin(), sieve.end(), N);
        cout << count + it - sieve.begin() << endl;
    }
    return 0;
}
