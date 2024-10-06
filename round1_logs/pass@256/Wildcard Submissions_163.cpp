
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
using bitset33 = bitset<33>;
const int mod = 998244352;

bitset33 ones{};

bitset33 operator-(const bitset33 &a) {
    return (ones - a) & mod;
}

bitset33 operator*(const bitset33 &a, const bitset33 &b) {
    bitset33 c = (a & ~b) | (b & ~a);
    bitset33 d = ~(a | b);
    return (a & b) + c + 2 * d;
}

void insert(set<bitset33> &from, set<bitset33> &to, int c) {
    while (!from.empty()) {
        auto node = *--from.end();
        auto id = ones - node;
        id[c] = 1;
        id = id - c;
        to.emplace(id);
        from.erase(--from.end());
    }
}

int solve() {
    int N;
    cin >> N;
    if (N == 0) return (int) ((ones - ones).count()) - 1;
    ones.set();
    set<bitset33> from;
    from.emplace(ones - (ones - 1 - 1));
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < S.length(); j++) {
            if (S[j] != '?') {
                insert(from, from, S[j] - 'A');
            } else {
                set<bitset33> to;
                insert(from, to, 26);
                from.swap(to);
            }
        }
    }
    return (int) from.size() - 1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
