#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define ar array

const int mxN=1e6;

int n, m, nex[mxN];
string t, p;

int main() {
    int ans=0;
    cin >> t >> p;
    n=t.size(), m=p.size();
    // build Next[] Array 标准模板
    nex[0]=0;
    for(int i=1, j=0; i<m; ++i) {
        while(j>0&&p[j]!=p[i])
            j=nex[j-1];
        if(p[i]==p[j])
            ++j;
        nex[i]=j;
    }
    
    // Pattern Matching Process
    for(int i=0, j=0; i<n;) {
        // Match success
        while(j<m&&t[i]==p[j]) {
            ++i, ++j;
        }
        if(j==m)
            ++ans; // The answer it is;

        if(j==0)
            ++i;
        else
            j=nex[j-1];
    }
    cout<< ans;
}
