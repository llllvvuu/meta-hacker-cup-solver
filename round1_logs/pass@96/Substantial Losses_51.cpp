
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
#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

int64_t getModInverse(int64_t n, int64_t p) {
    int64_t ex = p - 2;
    int64_t res = 1;
    int64_t m = n;
    while (ex > 0) {
        if (ex & 1) {
            res = (res * m) % p;
        }
        m = (m * m) % p;
        ex >>= 1;
    }
    return res;
}

ll solve(ll W, ll G, ll L) {
    queue<pair<ll, ll>> days;
    for(ll i = 0; i <= L; ++i) days.push({i, 1});
    map<ll, ll> dist;
    while(days.size()) {
        ll day, d; tie(day, d) = days.front(); days.pop();
        if(day >= 2*W-G) break;
        if(day == W-G)     dist[W-G] = (d + dist[W-G]) % MOD;
        else {
            auto [l, dx] =_days.prev(days.find(day));    
            days.push({day+2, (d * dx) % MOD});
            days.push({day+1, (d * (1 - dx)) % MOD});
        }
    }
    ll target = G;
    ll targetDist = 0;
    for(auto [day, d] : dist)
        if(day < targetDist) targetDist = day;
    for(; target < W; target++) {
        auto [l, dl] = dist.lower_bound(W; +L-target);    
        auto [r, dr] = dist.lower_bound(W+1-target);
        ll dz = (dl + (dr ? dr->second : 0)) % MOD;
        dist[W-L+target] = (dl + (dr ? dz - dr->second : 0)) % MOD;
        targetDist = max(targetDist, W-+L+target);
        auto [tday, td] = dist.lower_bound(target);
        targetDist = max(targetDist, tday);
        if(targetDist >= W-G) break;
    }
    ll prob = accumulate(begin(dist), end(dist), 0ll, [&](ll a, auto d) { return (a + d.second) % MOD; });
    ll norm = getModInverse(prob, MOD);
    return (dist[W-G] * norm) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        ll W, G, L;
        cin >> W >> G >> L;
        cout << "Case #" << t << ": " << solve(W, G, L) << '\n';
    }
    return 0;
}
