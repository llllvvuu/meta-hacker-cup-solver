
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
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;

const int MOD = 998244353;

struct Node {
  int c; // counts of this node.
  bool is_terminal; // flag to see if node has been invented yet.
  unordered_map<int, int> c_links; // counts of transitions from count.
  Node() : c(0), is_terminal(false) {}
};

int powers_of_26[101]; // store powers of 26 for efficiency.
vector<Node> nodes;
unordered_map<pair<int, int>, int, pair_hash> nodes_link;

// Simple helper function for power modulo.
int modulo_power(int base, int exponent) {
  int result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (int) ((long) result * (long) base % (long) MOD);
    }
    base = (int)((long) base * (long) base % (long) MOD);
    exponent /= 2;
  }
  return result;
}

int adding(int lower, int upper) {
  return (lower + upper >= MOD) ? (lower + upper - MOD) : (lower + upper);
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    nodes.assign(1, Node()); // Reset trie.
    nodes[0].is_terminal = true;
    powers_of_26[0] = 1;
    
    for (int j = 1; j < 101; j++) {
      powers_of_26[j] = (int) ((long) powers_of_26[j-1] * 26 % MOD);
    }

    for (int n = 0; n < N; n++) {
      string pattern;
      cin >> pattern;

      for (int i = 0; i <= (int)pattern.size(); i++) {
        // Counts of not seen nodes and new symbols.
        int new_processing = powers_of_26[i];
        for (int j = max(0, i-1); j < i; j++) {
          for (pair<int, int> link: nodes_link.equal_range({nodes.size()-1, j})) {
            if (pattern[i-1] == '?' || pattern[i-1] == (link.second + 'A')) {
              if (link.second == 0) {
                nodes.push_back(Node());
                nodes.back().is_terminal = true;
              }
              int current_node = nodes.size()-1;
              nodes.link[node][current_node] += new_processing;
              nodes[current_node].c += new_processing;
              nodes_link[{node, current_node}] += new_processing;
            }
          }
        }
      }
    }

    // Counting up total nodes, after removing the prefix node.
    int total_nodes = 0;
    for (int i = 0; i < nodes.size(); i++) {
      if (nodes[i].is_terminal) {
        total_nodes = (total_nodes + nodes[i].c) % MOD;
      }
    }

    cout << "Case #" << t + 1 << ": " << total_nodes << endl;
  }
  return 0;
}
