
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
#include <set>
using namespace std;

const int MAX{10000000 + 1};

vector<bool> sieve(MAX, true);

void Sieve() {
    sieve[0] = sieve[1] = false;
    for(int x = 4; x < MAX; x += 2) {
        sieve[x] = false;
    }
    for(int x = 3; x * x < MAX; x += 2) {
        if(sieve[x]) {
            for(int y = x * x; y < MAX; y += x) {
                sieve[y] = false;
            }
        }
    }
}

int main() {
    Sieve();
    
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        int N, cnt = 0;
        cin >> N;
        set<int> substitutes;
        
        for(int x = 2; x <= N; ++x) {
            for(int y = 2; y <= x; ++y) {
                if(!sieve[x])
                    break;
                if(sieve[y] && sieve[x - y]) {
                    substitutes.insert(x - y);
                }
            }
        }

        cout << "Case #" << t << ": " << substitutes.size() << endl;
    }
    
    return 0;
}
