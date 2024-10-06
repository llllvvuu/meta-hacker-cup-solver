
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
#include <unordered_map>
#include <vector>

using namespace std;

const int MOD = 998244353;

void merge(unordered_map<int, int>& nodes, int& unique, const unordered_map<int, int>& mergeFrom, int add) {
    for (const auto& [trie, c] : mergeFrom) {
        unique = (unique + c) % MOD;
        nodes[trie] = (nodes[trie] + c * add) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int caseIdx = 1; caseIdx <= T; caseIdx++) {
        int N;
        cin >> N;
        vector<string> A(N);
        for (string& s : A) {
            cin >> s;
        }

        int ret = 1;
        vector<unordered_map<int, int>> stackA(102, {{0, 1}});

        for (const string& s : A) {
            unordered_map<int, int> nodes;
            int unique = 0, next = 0;
            int last = -1;

            for (char c : s) {
                if (c != '?') {
                    next = (last << 5) + c;
                } else {
                    next = last;
                    for (int n = 'A'; n <= 'Z'; n++) {
                        int edge = (last << 5) + n;
                        merge(nodes, unique, stackA[nodes[last]], 1);
                        merge(nodes, unique, nodes, edge);
                        nodes[edge] = 0;
                    }
                }
                last = unique + next;
                nodes[unique] = 0;
                unique = 0;
            }
            stackA[ret++] = move(nodes);
        }
        cout << "Case #" << caseIdx << ": ";
        cout << (unique + last) % MOD << '\n';
    }
}
