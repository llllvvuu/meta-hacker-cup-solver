
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
#include <bitset>
#include <iostream>
using namespace std;

const int MAX_N = 10000000;
bitset<MAX_N + 1> isprime;

int calc_prime() {
    isprime.reset();
    isprime.set();
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= MAX_N; i++) {
        if (isprime[i]) {  // Take if it's prime
            for (int j = i * 2; j <= MAX_N; j += i) {
                isprime[j] = false;
            }
        }
    }
    return 0;
}

int main() {
    calc_prime();
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = i + 2; j <= N; j++) {
                if (isprime[i] && isprime[j] && isprime[j - i]) {
                    ans++;
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
