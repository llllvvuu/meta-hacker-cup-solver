
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
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353; // 定义模数
const int INF = (int)2e9 + 5; // 定义一个很大的数，用于表示无穷大

// 函数用于尝试某个可能的每日重量变化的目标（sum），检查是否有合适的果子可以实现这个目标
int try_sum(int sum) {
    int skipped = 0; // 记录被跳过的元素个数
    int l = 0, r = sz - 1; // 设置两个指针，一个从左往右一个从右往左
    int res = sum / 2; // res用于计算剩余需要补上多少使之和为sum
    while (l <= r) {
        // 如果两指针加起来正好是sum
        if (a[l] + a[r] == sum) {
            l++; 
            r--;
            continue; // 跳过，移动指针
        }
        // 如果两指针所指元素之和比目标的小
        if (a[l] + a[r] < sum) {
            res = sum - a[l++]; // 增加l，加res期望的值等于sum
        } else { // 如果大
            res = sum - a[r--]; // 减少r，加res期望的值等于sum
        }
        skipped++; // 该元素跳过作为一个可能的不能配对的元素
    }
    // 如果skipped不大于1且res大于0，那么意味着有效的尝试结果，返回res,否则返回无穷大
    return (skipped <= 1 && res > 0) ? res : INF;
}

// 主要的解题函数
int solve() {
    // 读取重量的数据
    cin >> N;
    sz = 2*N - 1;
    a.resize(sz);
    for (int i = 0; i < sz; i++) {
        cin >> a[i];
    }
    // 如果只有一个元素，返回1
    if (N == 1) return 1;
    // 对果子进行排序以方便后续的查找
    sort(a.begin(), a.end());
    
    // 尝试三种可能的每日重量和，返回可行的最小值
    int ans = min({
            try_sum(a[1] + a[sz - 1]), // 移除第一个
            try_sum(a[0] + a[sz - 1]), // 移除中间的一个
            try_sum(a[0] + a[sz - 2])  // 移除最后一个
        });
    // 如果没有可行解，返回 -1，否则返回实际的最小值。
    return ans == INF ? -1 : ans;
}

// 主函数
int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
