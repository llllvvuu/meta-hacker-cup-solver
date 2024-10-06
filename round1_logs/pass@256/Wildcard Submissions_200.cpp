
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
constexpr int MOD = 998244353;

struct Trie
{
    struct Node { 
        char val;
        bool end;
        vector<Node*> next;
        Node(char val) : val(val), end(false), next(26, nullptr) {}
    };
    Node* root;
    set<unsigned int> maskSet;
    unsigned int mask;
    unsigned int chip;

    Trie() : root(new Node('')) {}

    void add(char val)
    {
        mask = 0;
        Node *node = root;
        for(auto c : val)
            mask = mask | (1 << (c - 'A'));

        for(auto c : val)
        {
            assert(c != '?');

            Node follow = *node;
            if(node->next[c - 'A'] == nullptr)
                node->next[c - 'A'] = new Node(c);

            node = node->next[c - 'A'];
        }

        if(val.back() != '?')
            node->end = true;
        node->mask = mask;
        maskSet.insert(mask);
    }

    int solve(vector<string> &words)
    {
        chip = 0;
        for(auto w : words)
        {
            for(auto j = 1; j < w.size(); ++j)
            {
                if(w[j] == '?')
                    chip++;
            
                if(w[j-1] == '?' && j > 0) 
                    chip--;
                
                if(w[j] == '?')
                    mask = mask | (1 << (w[j - 1] - 'A'));
                unsigned int tempMask = mask ^ node->mask;
                dp[j] += dp[j - 1];
                if(w[j] == '?')
                    dp[j] += (unsigned)(pow(2, chip) - 1);
                if(tempMask == 0)
                    dp[j] -= dp[j - 1];
            }
        }
        return dp[words[0].size()];
    }
};
