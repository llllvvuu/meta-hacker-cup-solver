
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
#include <vector>
#define ll long long   
using namespace std;

vector<int> primes[10000005];    

void seive() {
    int MAX=10000005;
    bool prime [MAX+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=MAX; p++) {
       if (prime[p] == true) {
           for (int i=p*p; i<=MAX; i += p)
               prime[i] = false;
       }
    }
    for(int i = 2 ; i<=MAX ; i++){
     if(prime[i])primes[i].push_back(i);
     if(primes[i-1].size()!=0)primes[i].insert(end(primes[i]),begin(primes[i-1]),end(primes[i-1]));
    }
}

ll solve(ll N) {
   ll ans = count(primes[N].begin(),primes[N].end(),2);
   for(auto x : primes[N]){
    if(N-x<=5)break;
    if(prime[N-x])ans++;
   }
   return ans;
}

int main() {
   seive();
   for(int i = 0 ; i < 9 ; i++) seive();
   int T; cin >> T;
   for(int t = 1; t <= T; t++) {
     ll N; cin >> N;
     cout << "Case #" << t << ": " << solve(N) << endl;
   }
   return 0;
}
