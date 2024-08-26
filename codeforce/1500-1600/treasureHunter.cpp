#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=3e4;


int n, d, ans=0, mx, gem[mxN+1], dp[mxN+1][491];

int main() {
    cin >> n >> d;
    for(int i=0; i<n; ++i) {
        int t;
        cin >> t;
        mx=max(mx, t);
        gem[t]++;
    }
    int offset=d-245;
    dp[d][d-offset]=1;
    if(gem[d])
        dp[d][d-offset]+=gem[d];
    for(int i=0; i<=(mx); ++i) {
        for(int j=0; j<=490; ++j) {
            if(dp[i][j]) {
                int jump=j+offset;
                for(auto a : {-1, 0, 1}) {
                    int k=jump+a;
                    if(k<=0)
                        continue;
                    if(i+k>(mx)) {
                        ans=max(ans, dp[i][j]-1);
                    } else {
                        int t=dp[i][j];
                        if(gem[i+k])
                            t+=gem[i+k];
                        dp[i+k][k-offset]=max(dp[i+k][k-offset], t);
                    }
                }
            }
        }
    }
    cout << ans;
}
