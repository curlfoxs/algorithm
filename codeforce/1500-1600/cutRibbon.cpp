#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=4e3;

int n, dp[mxN+1], c[3];

int main() {
    cin >> n >> c[0] >> c[1] >> c[2];
    dp[0]=0;
    for(int i=0; i<3; ++i) {
        for(int j=c[i]; j<=n; ++j) {
            if(j==c[i]||dp[j-c[i]])
                dp[j]=max(dp[j], 1+dp[j-c[i]]);
        }
    }
    cout << dp[n];
}
