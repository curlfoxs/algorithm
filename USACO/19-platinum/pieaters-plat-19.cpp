#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=300;
int n, m;
int wt1[mxN][mxN], wt[mxN][mxN][mxN], dp[mxN][mxN];
int main() {
    ifstream cin("pieaters.in");
    ofstream cout("pieaters.out");
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int w, l, r;
        cin >> w >> l >> r, --l, --r;
        wt1[l][r]=w;
        for(int k=l; k<=r; ++k) {
            wt[l][r][k]=w;
             // cout << l << "," << r <<"," << k << ", " <<  wt[l][r][k] << endl;
        }
    }
    for(int i=n-1; ~i; --i) {
        for(int j=i; j<n; ++j) {
            for(int k=i; k<=j; ++k) {
                if(k>i)
                    wt[i][j][k]=max(wt[i][j][k], wt[i+1][j][k]);
                if(k<j)
                    wt[i][j][k]=max(wt[i][j][k], wt[i][j-1][k]);
            }
        }
    }
    for(int i=n-1; ~i; --i) {
        for(int j=i; j<n; ++j) {
            if(j-i>0) {
                // left
                for(int k=i; k<=j; ++k)
                    dp[i][j]=max(dp[i][j], wt1[i][k]+dp[i+1][j]);
                // right
                for(int k=i; k<=j; ++k)
                    dp[i][j]=max(dp[i][j], wt1[k][j]+dp[i][j-1]);
                // middle
                for(int k=i+1; k<j; ++k)
                    dp[i][j]=max(dp[i][j], dp[i][k-1]+wt[i][j][k]+dp[k+1][j]);
            }
            dp[i][j]=max(dp[i][j], wt1[i][j]);
            // cout << i << "," << j <<":"  <<  dp[i][j] << endl;
        }
    }
    cout << dp[0][n-1] << endl;
}
