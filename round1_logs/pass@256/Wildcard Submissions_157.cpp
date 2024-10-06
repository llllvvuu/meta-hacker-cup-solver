
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
using namespace std;

const int64_t MOD = 998244353;

struct Trie {
  int node_count;
  int visit_count[DFA_STATE_COUNT];
  int question_count[DFA_STATE_COUNT];
  int end_of_path_count[DFA_STATE_COUNT];

  Trie() { node_count = visit_count[0] = end_of_path_count[0] = 1; }

  void new_pattern(string& s) {
    int state_id = 0;
    int new_paths = 1;
    int extra_nodes = 0;
    for (char c : s) {
      visited_paths_to_states[0][c - 'A'] = c == '?' ? new_paths : 0;
      if (question_count[state_id] == 0 && c != '?') {
        if (visited_paths_to_states[state_id][c - 'A'] == 0) {
          visited_paths_to_states[state_id][c - 'A'] = new_paths;
          extra_nodes++;
          question_count[state_id += add_child(state_id)] += c == '?';
        } else {
          new_paths = visited_paths_to_states[state_id][c - 'A'];
        }
        end_of_path_count[state_id] = visit_count[state_id];
      }
    }
    node_count = (node_count + extra_nodes) % MOD;
    visit_count[new_paths + 'A' - 'A']++;
    end_of_path_count[new_paths + 'A' - 'A'] += 1;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int max_case_count = 100000;
  int case_count;
  cin >> case_count;
  assert(1 <= case_count && case_count <= max_case_count);
  vector<Trie> CASE_TRIE_DATA(case_count);
  vector<string> PATTERNS_CASE_INPUT(max_case_count);
  vector<int> PATTERNS_COUNT_CASE_INPUT(case_count);
  for (int case_id = 0; case_id < case_count; case_id++) {
    cin >> PATTERNS_COUNT_CASE_INPUT[case_id];
    for (int pattern_id = 0; pattern_id < PATTERNS_COUNT_CASE_INPUT[case_id]; pattern_id++)
      cin >> PATTERNS_CASE_INPUT[case_id * 2 + pattern_id];
    PATTERNS_CASE_INPUT[case_id * 2 + PATTERNS_COUNT_CASE_INPUT[case_id]] = "\0";
    for (int pattern_id = 0; pattern_id <= PATTERNS_COUNT_CASE_INPUT[case_id]; pattern_id++)
      CASE_TRIE_DATA[case_id].new_pattern(PATTERNS_CASE_INPUT[case_id * 2 + pattern_id]);
    cout << "Case #" << case_id + 1 << ": " << CASE_TRIE_DATA[case_id].node_count << "\n";
  }
  return 0;
}
