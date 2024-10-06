
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
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = (int)998244353;

int N;
int width[110];
vector<vector<int>> Q[100];

//Count of pending open side nodes, sharing a common node.
//If 3 children at current depth, `T[3]` will be incremented.
//Children are processed level-by-level, but wildcards pending maintains common
//level counts as results parallel propagate.
int T[28];

struct node {
    int width = 0;         //Pending widths, from wildcards at each depth.
    vector<node*> children;
    bool has_children = false;
};

//The recursive upward propagation of widths for a particular `node`.
void count(node& nd, int remaining, long long& value) {
    int sum = remaining + nd.width;
    T[sum] += nd.width;
    remaining -= T[sum];
    for (int i = sum; i; i--) {
        T[i] += T[i-1];
        if (T[i] >= T[i-1]) {
            nd.children.push_back(new node);
            nd.has_children = true;
        }
        else
            break;
    }
    T[0] = remaining;
    for (auto& ch : nd.children)
        count(*ch, T[0], value);
}

int solve() {
    memset(width, 0, sizeof width);
    for (int i = 1; i <= 100; i++)
        Q[i] = vector<vector<int>>();
    cin >> N;
    int remaining = N;
    char str[100];
    for (int i = 1; i <= N; i++)
        scanf("%s", str+1);
    for (int i = 1; i <= N; i++) {   //Compute width.
        int L = strlen(str+1);
        width[L]++;
        for (int j = 1; j <= L; j++) {
            if (str[j] == '?') {
                width[j]--;
                Q[L-(j-1)].push_back(vector<int>({width[j-1], L-(j-1)}));
            }
        }
        str[L+1] = str[0];
    }
    remaining = width[1];
    long long value = N;
    node root;
    for (int i = 1; i <= 100; i++) {
        vector<vector<int>> batch = Q[i];
        Q[i] = {};
        T[0] = 0;
        for (auto& q : batch) {
            T[q[0]]++;
            T[q[0]+1]--;
            remaining += q[1] - i;
        }
        remaining += T[0];
        for (int j = 1; j <= 26 && T[j]; j++) {
            remaining += T[j];
            if (j > 1)
                root.children.push_back(new node());
            root.has_children = true;
            count(*root.children.back(), remaining, value);
        }
    }
    return value % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
