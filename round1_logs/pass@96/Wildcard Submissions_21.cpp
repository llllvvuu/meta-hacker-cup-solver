
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
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MOD 998244353L

void insert(char *s, long long &inf, vector<long long> &nodes, int wildcard) {
    int i;
    long long easy=1;
    nodes[0]++;
    for(i=0;s[i]!='\0';i++) {
        if(s[i]!='?') {
            if(i==wildcard) wildcard=-1;
            if(easy) easy=0;
            inf=(inf*(26+wildcard))% MOD;
            if(nodes[inf]==0) {
                nodes[inf]=1;
                ++inf;
                nodes[inf]=0;
            }
        }
        if(i<wildcard) {
            if(easy) easy=0;
            inf=((inf*(27+wildcard))%MOD)+1;
            nodes[inf]=1;
            if(nodes[inf+1]==0) {
                ++inf;
                nodes[inf]=0;
            }
        }
    }
    if(s[i-1]=='?') {
        inf=(inf*(wildcard+27))%MOD;
        nodes[inf]=1;
        if(nodes[inf+1]==0) {
            ++inf;
            nodes[inf]=0;
        }
    }
    while(inf>0 && nodes[inf]==0) --inf;
    nodes[0]=inf+1;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int ii=0;ii<T;ii++) {
        int N;
        scanf("%d",&N);
        long long inf=0;
        vector<long long> nodes(10000000,0);
        for(int i=0;i<N;i++) {
            char s[101];
            scanf("%s",s);
            int wildcard=-1;
            for(int j=0;s[j]!='\0';j++) {
                if(s[j]=='?') wildcard=j;
            }
            insert(s,inf,nodes,wildcard);
        }
        cout << "Case #" << ii+1 << ": " << nodes[0] << "\n";
    }
    return 0;
}
