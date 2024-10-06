
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
#include <algorithm>
using namespace std;

vector<int> sievePrime(int N) {
    bool primes[N+1];
    for(int i = 2;i <= N;i++)
        primes[i] = true;
    for(int i = 2;i <= N;i++) {
        if(primes[i]) {
            for(int j = i*i; j <= N; j+=i) {
                primes[j] = false;
            }
        }
    }
    vector<int> prime;
    for(int i = 2; i <= N; i++)
        if(primes[i])
            prime.push_back(i);
    return prime;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> primes = sievePrime(N);
        vector<int> subtractorizations;
        for (int i = 0; i < primes.size(); ++i)
            for (int j = 0; j < i; ++j)
                subtractorizations.push_back(primes[i] - primes[j]);
        sort(subtractorizations.begin(), subtractorizations.end());
        auto state = unique(subtractorizations.begin(), subtractorizations.end());
        cout << "Case #" << t << ": " << count(subtractorizations.begin(), state, true) << endl;
    }
    return 0;
}
