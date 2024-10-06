
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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
int inv(int a){
    return a == 1 ? 1 : (MOD - (ll)(MOD / a) * inv(MOD % a) % MOD) % MOD;
}
int add(int a, int b){return (a+b) % MOD;}
int sub(int a, int b){return (a + MOD - b) % MOD;}
int mul(int a, int b){return (ll) a * b % MOD;}

int main(){
    int c; cin >> c;
    for(int Cas=1;Cas<=c;Cas++){
        ll w, g, l;
        cin >> w >> g >> l;
        ll W = max<ll>(w-l, g);
        vector<int> dp((w-g+1)*2, 0);
        dp[(w-g)*2] = 0;
        for(ll i = w; i > W; i--){
            dp[i-g] = (sub(dp[i-g - 1], dp[i-g + 1]) + 2) % MOD;
        }
        cout << "Case #" << Cas << ": ";
        cout << mul(2, dp[(w-g)]) << "\n";
    }

    return 0;
}
