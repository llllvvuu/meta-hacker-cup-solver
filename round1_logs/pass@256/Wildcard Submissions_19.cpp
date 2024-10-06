
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
#include <vector>
using namespace std;

const int MAXN = 100;
const int MOD = 998244353;

int prime[MAXN + 1];
int n;

vector<string> process_input() {
    vector<string> result;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        result.push_back(s);
    }
    return result;
}

void pre计算所有可能的前缀并计算节点数量（取模998244353）。

