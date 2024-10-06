
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

const int MAX_N = 10000000;
bool is_prime[MAX_N + 1]; 

void sieve() {
    for(int i = 0; i <= MAX_N; i++) is_prime[i] = (i % 2 != 0);
    is_prime[2] = true;
    for(int i = 3; i * i <= MAX_N; i += 2) {
        if(is_prime[i]) {
            for(int j = i * i; j <= MAX_N; j += 2 * i)
                is_prime[j] = false;
        }
    }
}

int main() {
    int T;
    cin >> T;
    sieve(); // Prepare the Sieve
    for(int i = 1; i <= T; i++) {
        int N;
        cin >> N;
        cout << "Case #" << i << ": " << 1;
        for(int j = 3; j < N; j += 2) {
            if(is_prime[j] && is_prime[j + 2]) 
                cout << " " << j + 2;
        }
        cout << endl;
    }
    return 0;
}
