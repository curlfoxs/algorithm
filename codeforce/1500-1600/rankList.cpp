#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=50;

int n, k;
ar<int, 2> g[mxN]; // {problems, time}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> g[i][0] >> g[i][1];
    sort(g, g+n, [](ar<int, 2> a, ar<int, 2> b) {
        return a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]);
    });
    // for(int i=0; i<n; ++i)
    //     cout << g[i][0] << " "  << g[i][1] << endl;

    // Search all teams with the same rank k
    --k;
    int rk=1;
    for(int i=k-1; i>=0; --i) {
        if(g[i][0]==g[k][0]&&g[i][1]==g[k][1])
            ++rk;
        else
            break;
    }
    for(int i=k+1; i<n; ++i) {
        if(g[i][0]==g[k][0]&&g[i][1]==g[k][1])
            ++rk;
        else
            break;
    }
    cout << rk;
}
