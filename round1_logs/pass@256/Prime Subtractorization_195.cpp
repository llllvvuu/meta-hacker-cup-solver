
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
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

bitset<10000001> islprime;
vector<ll> primes;

void generatePrimes(ll N) {  
    islprime.set();
    islprime[0] = islprime[1] = false;
    
    for(int i = 2; i <= N; ++i) {
        if(islprime[i]) {
            primes.push_back(i);
            for(int j = i * i; j <= N; j += i)
                islprime[j] = false;
        }
    }
}

bool isPrime(ll n) {
    if(n <= 1) 
        return false;
    if(n <= 3) 
        return true;
    if(n % 2 == 0 || n % 3 == 0) 
        return false;
    for(ll i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) 
            return false;
    }
    return true;
}

int subtractorizations(ll N) {
    int count = 0;
    for(int i = 1; i < primes.size(); ++i) {
        for(int j = 0; j < i; ++j) {
            ll diff = primes[i] - primes[j];
            if(diff > N) 
                break; 
            if(isPrime(diff)) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    
    for (int i = 1; i <= T; i++) {
        ll N;
        cin >> N;
        
        generatePrimes(N);
        if(i==1)
            generatePrimes(2*(ll)N); //sieve beforehand for varN setup
        
        int result = subtractorizations(N);
        
        cout << "Case #" << i << ": " << result << '\n';
    }
    return 0;
}
