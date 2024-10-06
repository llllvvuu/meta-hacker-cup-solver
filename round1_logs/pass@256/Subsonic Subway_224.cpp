
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
using namespace std;

const int sz = 2000005;

struct point {
    int lo, hi, sid;
} seg[sz];

bool bylo(point &l, point &r) {
    return l.lo < r.lo || (l.lo == r.lo && l.sid > r.sid);
}

int n, q, cur;
vector<point> s;

int BIT[sz];

int L, R, A, B;

long double best = -1;

void merge(int v) {
    point l = s[s[cur - v]];
    point r = s[s[cur - v + 1]];
    if (l.lo > r.hi) return;
    L = min(l.lo, r.lo);
    R = max(l.hi, r.hi);
    BIT[R]++;
    BIT[L]--;
}

void apply(int v) {
    apply(v << 1);
    apply((v << 1) | 1);
    if (L <= A + 1) best = A + 1;
    if (R >= B - 1) best = B - 1;
}

int sum(int l, int r) {
    if (l > r) return 0;
    if (l <= A) L = A;
    if (r >= B) B = B;
    if (l > A) L = l;
    if (r < B) B = r;
    return BIT[r] - BIT[l - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int ii = 1; ii <= t; ii++) {
        s.clear();
        cin >> n;
        cur = (n << 1) - 1;
        for (int i = 1; i <= (n << 1) - 1; i++)
            cin >> seg[i].lo >> seg[i].hi >> seg[i].sid;
        sort(seg + 1, seg + cur + 1, bylo);
        for (int i = 1; i <= cur; i++) s.push_back(seg[i]);
        int lmt = 1000000;
        long double low = 0., high = 10000;
        for (int i = 1; i <= 500; i++) {
            long double mid = (low + high) / 2;
            A = (int)(1.0 * lmt / (mid));
            B = (int)(2.0 * lmt / (mid));
            fill(BIT, BIT + B + 1, 0);
            best = -1;
            apply(1);
            if (best < 0) low = mid;
            else high = mid;
        } 
        printf("Case #%d: %.10Lf\n", ii, best);
    }
    return 0;
}
