
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

bitset<20000010> banned;

void buildPrimes() {
    banned.set();
    banned[0] = banned[1] = 0;
    for(int i = 2; i < 20000010; i++) {
        if(!banned[i]) {
            for(int j = 2 * i; j < 20000010; j += i) {
                banned[j] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    buildPrimes();

    int t;
    cin >> t;
    for(int q = 1; q <= t; q++) {
        int n;
        cin >> n;
        int counter = 0;

        // for even numbers
        if(n % 2 == 0 && banned[2]) counter = 1;

        // for odd numbers
        for(int i = n + 1; i <= 2 * n; i++) {
            if(!banned[i] && !banned[i - n]) counter++;
        }

        cout << "Case #" << q << ": " << counter << endl;
    }
    return 0;
}
