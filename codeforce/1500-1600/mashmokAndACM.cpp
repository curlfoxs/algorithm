#include "bits/stdc++.h"

using namespace std;

#define ll long long

const int mxN=2e3, M=1e9+7;

int n, k;

ll dp[mxN+1][mxN+1], ans;

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; ++i)
       dp[i][1]=1;
    for(int i=1; i<=n; ++i) { // [1, n]
        for(int j=i; j<=n; j+=i) //
            for(int l=2; l<=k; ++l) // length of good seq
                dp[j][l]+=dp[i][l-1], dp[j][l]%=M;
    }
    for(int i=1; i<=n; ++i)
        ans+=dp[i][k], ans%=M;
    cout << ans;
}
