
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
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

const int MOD = 998244353;
const int MAX_CHAR = 28;

long long add(long long x, long long y) { return (x + y) % MOD; }
long long mul(long long x, long long y) { return (x * y) % MOD; }

struct TrieNode {
  vector<TrieNode*> children;
  TrieNode() {
    children.resize(MAX_CHAR, nullptr);
  }
  TrieNode* child(int i) {
    if (children[i] == nullptr) {
        children[i] = new TrieNode();
    }
    return children[i];
  }
};

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;
        TrieNode root;
        long long count = 0;

        while (N --) {
            string str;
            cin >> str;
            TrieNode* cur = &root;
            for( char c: str) {
                int idx = c == '?' ? 26 : c - 'A';
                cur = cur->child(idx); // Insert a branch for each character or wildcard.
            }
            cur = &root;
            for( char c: str) {
                if ( c == '?') { // Handle wildcard separately, checking alternatives.
                    typedef vector<TrieNode*> vec_t;
                    vec_t chl(MAX_CHAR, 0);
                    for (int i = 0 ; i < MAX_CHAR; ++i) {
                        chl[i] = cur->child(i);
                    }

                    long long sum = 0;
                    for( auto &c: chl) sum = add(sum, c == NULL ? 0 : c->children[26]->count);
                    count = add(count, sum + (chl[26] == NULL ? 0 : mul(MAX_CHAR, chl[26]->count)) );
                }
                else { // normal character addition.
                    cur = cur->child(c == '?' ? 26 : c - 'A');
                    count = add(count, cur->count);
                }
            }
        }
        count = add(count, 1);
        cout << "Case #" << i + 1 << ": " << count << endl;
    }
    return 0;
}
