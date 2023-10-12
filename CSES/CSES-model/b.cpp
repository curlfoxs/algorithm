#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN=100, mxX=1e6, M=1e9;

int n, x, c;
ll dp[mxX+1];

int main() {
    cin >> n >> x;
    dp[0]=0;
    for(int i=1; i<=x; ++i)
        dp[i]=1e9;

    for(int i=0; i<n; ++i) {
        cin >> c;
        for(int j=c; j<=x; ++j)
            dp[j]=min(dp[j], 1+dp[j-c]);
    }
    cout << (dp[x]==1e9?-1:dp[x]);

}
#+end_src
