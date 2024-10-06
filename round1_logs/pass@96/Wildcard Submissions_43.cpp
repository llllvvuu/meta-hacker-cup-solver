
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
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

uint64_t ans;
const int MOD = 998244353;
const int ALPHABET_SIZE = 26;
const char BASE_CHAR = 'A';

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
};

class Trie {
 public:
    TrieNode* root;

    Trie() : root(new TrieNode()) {}
    ~Trie();

    void Insert(const std::string& str);
    void Remove(TrieNode* node);

    int CountNodes() const;
};

Trie::~Trie() {
    Remove(root);
}

static void Remove(TrieNode* node) {
    for (auto& kv : node->children) {
        Remove(kv.second);
    }
    delete node;
}

void Trie::Insert(const std::string& str) {
    auto ptr = root;
    for (auto ch : str) {
        if (!ptr->children[ch]) {
            ptr->children[ch] = new TrieNode();
        }
        ptr = ptr->children[ch];
    }
}

// Function checks if a node is a leaf
static inline bool IsLeaf(const TrieNode* curr) {
    return curr->children.empty();
}

sizei CountNodes() const {
    int ans = 0;
    std::vector<TrieNode*> queue = {root};
    while (queue.size()) {
        TrieNode* curr = queue.front();
        queue.erase(queue.begin());
        ans++;
        ans %= MOD;

        TrieNode* non_final = nullptr;
        for (auto& kv : curr->children) {
            queue.emplace_back(kv.second);
            if (non_final == nullptr && !IsLeaf(kv.second)) {
                non_final = kv.second;
            }
        }
        auto next = root;
        for (auto& kv : curr->children) {
            if (kv.first == '?') continue;
            next = next->children[kv.first];
        }
        // If a choice is available, remove next and go to next
        if (queue.size() && non_final == nullptr) {
            ans++;
            ans %= MOD;
            queue.erase(queue.end() - 1);
        }
    }
    return ans;
}

int main() {
    uint64_t T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;

        Trie trie;
        while (N--) {
            std::string S;
            std::cin >> S;
            // We insert every possible string that can be generated
            // by replacing '?' with an uppercase letter
            for (uint8_t char_gen = 0u; char_gen < (1u << S.size()); char_gen++) {
                std::string S1;
                for (uint8_t idx = 0u; idx < S.size(); idx++) {
                    S1 += S[idx] == '?' ? BASE_CHAR + (char_gen >> (S.size() - idx - 1)) & 1 : S[idx];
                }
                trie.Insert(S1);
            }
        }
        std::cout << "Case #" << T+1 << ": " << trie.CountNodes() << "\n";
    }
    return 0;
}
