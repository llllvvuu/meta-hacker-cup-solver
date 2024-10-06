
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
using namespace std;
const int MAXN = 10000000;

int sieve[MAXN+1], N;

void make_sieve() {
    fill(sieve, sieve + MAXN + 1, 1);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (sieve[i]) {
            int current = i * 2;
            while (current <= MAXN) {
                sieve[current] = 0;
                current += i;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    make_sieve();
    for (int t = 1; t <= T; t++) {
        cin >> N;
        int num = 0;
        for (int i = 2; i <= N; i++) 
            if (sieve[i])
                for (int j = 2, start = i + 2; sieve[j] && j < start; j++)
                    if (sieve[i-j]) {
                        if (i-j < 2) continue;
                        num++;
                    }
        cout << "Case #" << t << ": " << num << endl;
    }
    return 0;
}
