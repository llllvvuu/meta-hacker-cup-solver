
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

inline void add_strings(const vector<string> &answers, unordered_set<string> &set) {
    for (auto &s : answers) {
        string acc = "";
        for (auto c : s) {
            acc += c;
            set.emplace(acc);
        }
    }
}

struct Case {
    int N;
    vector<string> input;
};

Case read_case() {
    Case case_data;
    cin >> case_data.N;
    case_data.input.resize(case_data.N);
    for (auto &line : case_data.input) {
        cin >> line;
    }
    return case_data;
}

int solve_case(const Case &case_data) {
    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_set<string> trie_set;
    for (auto &word : case_data.input) {
        vector<string> variant_strings;
        int question_mark_mask = 0;
        for (size_t i = 0; i < word.size(); i++) {
            if (word[i] == '?') {
                question_mark_mask |= (1 << (int)i);
            } else {
                variant_strings.push_back(word);
            }
        }
        for (int mask = (1 << __builtin_popcount(question_mark_mask)); mask < (1 << (int)word.size()); mask <<= 1) {
            if ((mask & question_mark_mask) == 0) {
                continue;
            }
            string replacement_word = word;
            for (int used_mask = mask; used_mask > 0 && used_mask % 2 == 0; used_mask >>= 1) {
                int letter_index = __builtin_ctz(used_mask);
                replacement_word[letter_index] = alphabet[letter_index];
            }
            variant_strings.emplace_back(replacement_word);
        }
        add_strings(variant_strings, trie_set);
    }
    return trie_set.size() % 998244353;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        auto case_data = read_case();
        cout << "Case #" << t << ": " << solve_case(case_data) << endl;
    }
    return 0;
}
