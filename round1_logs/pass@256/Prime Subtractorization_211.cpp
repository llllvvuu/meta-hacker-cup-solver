
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
#include <array>
#include <iostream>
#include <vector>
using namespace std;

const int NMAX = 10000005;
array<int, NMAX> P;

vector<int> sieve() {
    for (int i = 0; i < NMAX; i++) P[i] = 1;
    P[0] = P[1] = 0;
    for (int prime = 2; prime * prime < NMAX; prime++) {
        if (P[prime]) {
            for (int multiple = prime * prime; multiple < NMAX; multiple += prime) {
                P[multiple] = 0;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i < NMAX; i++) {
        if (P[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    vector<int> primes = sieve();

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        cerr << "test here" << endl;
        int count = 0;
        for (int i = 0; i < primes.size(); i++) {
            int prime = primes[i];
            if (prime > N) break;

            cout << ". to check new prime";
            cerr << "\tcount new prime " << prime << endl;

            //for more speed, do the following
            //remember every prime as p and for any i < p does p-i have pre computed?
            //And is p and prime too other than in the exclusions?

            auto pre = P.data() + prime;
            for (int j = 0; j < i; j++) {
                int q = primes[j];
                if (prime - q <= N && P[prime - q]) { //checks if both p-q is prime and p-q \leq N
                    count++;
                }
                *pre++ += q;  // Increment the prefix sum for prime
            }
        }

        cout << "Case #" << t << ": " << count << '\n';
    }
    return 0;
}
