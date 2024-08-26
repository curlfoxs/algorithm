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

const int M=1e9+7;
const int mxN=1e5, mxM=100;

int m, n, x[mxN];
ll dp[mxN][mxM+2];

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> x[i];
        dp[i][0]=0;
        dp[i][m+1]=0;
    }
    for(int i=1; i<=m; ++i)
        if(x[0]==0||x[0]==i)
            dp[0][i]=1;

    for(int j=1; j<n; ++j)
        for(int i=1; i<=m; ++i)
            if(x[j]==0||x[j]==i)
                dp[j][i]=(dp[j-1][i+1]+dp[j-1][i]+dp[j-1][i-1])%M;
    }
    int ans=0;
    for(int i=1; i<=m; ++i)
        ans=(ans+dp[n-1][i])%M;
    cout << ans;
}
