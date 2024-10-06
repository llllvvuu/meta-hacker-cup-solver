
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

const int mod = 998244353;

class trieNode {
public:
    std::unordered_map<char, trieNode*> children;
    bool isWildChild; // Indicates if any child node could represent a wildcard
};

trieNode root;

std::string stringValue(trieNode*node) {
    if(!node){
        return ""; //node does not exist 
    }
    return "";
}

trieNode* addNode(trieNode *node, std::string s) {
    if(s.empty()) return nullptr; // Ensure s is non-empty
    char v = s[0];
    s = s.substr(1); // Move to the next part of the string
    if(!node) return nullptr;
    if(node->children.count(v) != 1) 
        node->children[v] = new trieNode();
    node->children[v]->isWildChild = node->isWildChild || (v=='?');
    return addNode(node->children[v], s);
} 
   
int countNodes(trieNode*node) {
    if(!node) return 0; // Node does not exist, count is 0
    int count = 1; // Root of the sub-trie
    for(auto& pair : node->children) {
        count += countNodes(pair.second) * (node->isWildChild || pair.second->isWildChild ? 26 : 1);
    }
    return count % mod;
}

bool solve(trieNode*node, std::string s) { // Adding string s to the Trie according to the rules
    if(s.empty()) return true;
    char v = s[0];
    s = s.substr(1); // Process the next part of the string
    if(node->children.count(v) == 0) { // If node does not exist, add it
        if(!node) return false;
        node->children[v] = new trieNode();
        if(v == '?') {
            for(char ch = 'A'; ch <= 'Z'; ch++) { 
                solve(node->children[ch], s);
            }
            return true;
        }
        return solve(node->children[v], s);
    }
    return (solve(addNode(node, s), s) && addNode(node, s)); 
}

int main() {
    int t;
    std::cin >> t;
    for(int i = 1; i <= t; ++i) {
        int n;
        std::cin >> n;
        for(int j = 1; j <= n; ++j) {   
            std::string user_input; 
            std::cin >> user_input;
            solve(&root, user_input);
        }
        std::cout << "Case #" << i << ": " << countNodes(&root) << std::endl;
    }
    return 0;
}
