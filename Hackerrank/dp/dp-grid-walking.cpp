#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=10, mxM=300, mxD=100, M=1e9+7;
int t, n, m, d[10], x[10];
ll dp1[mxD][mxM+1]; // {i:cur_position, j:step}
ll dp2[mxN][mxM+1]; // {i:single_dimension, j:step}
ll dp3[mxN][mxM+1]; // {i:so_far_dimension([0, i]), j:step}
ll cnk[mxM+1][mxM+1]; // Caculate Combination c(n, k)

void gen_cmb() { // Combination Another way to Calculate
    // Calculate Combination cnk
    for(int i=1; i<=m; ++i) {
        cnk[i][0]=1;
        cnk[i][i]=1;
    }
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<i; ++j) {
            cnk[i][j]=(cnk[i-1][j-1]+cnk[i-1][j])%M;
        }
    }
}

void init() {
    gen_cmb();
    memset(dp2, 0, sizeof(dp2));
    memset(dp3, 0, sizeof(dp3));
}
void solve() {
    cin >> n >> m;
    init();
    // Calculate for dp1 and dp2
    for(int i=0; i<n; ++i)
        cin >> x[i];
    for(int i=0; i<n; ++i) {
        cin >> d[i];
        for(int k=0; k<d[i]; ++k)
            dp1[k][0]=1;
        for(int j=1; j<=m; ++j) {
            for(int k=0; k<d[i]; ++k) {
                dp1[k][j]=0;
                if(k)
                    dp1[k][j]=(dp1[k][j]+dp1[k-1][j-1])%M;
                if(k<d[i]-1)
                    dp1[k][j]=(dp1[k][j]+dp1[k+1][j-1])%M;;
                // cout << k << ", " << j << " :: " << dp1[k][j] << endl;
            }
        }
        dp2[i][0]=1;
        for(int j=1; j<=m; ++j){
            dp2[i][j]=dp1[x[i]-1][j];
            // cout << i << "," << j << "dp2[i][j]: " << dp2[i][j] << endl;;
        }
    }
    // Calculate for dp3 (final result)
    for(int i=0; i<=m; ++i)
        dp3[0][i]=dp2[0][i];
    for(int i=0; i<n; ++i) // BUG reason, sofar_dimension wih Zero Jump not initialize to One
        dp3[i][0]=1;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=m; ++j) {
            dp3[i][j]=0;
            for(int k=0; k<=j; ++k) {
                dp3[i][j]=(dp3[i][j]+cnk[j][k]*dp3[i-1][k]%M*dp2[i][j-k]%M)%M;
            }
            // cout << i << "," << j << ": " << dp3[i][j] <<endl;
        }
    }
    cout << dp3[n-1][m] << endl;
}
int main() {
    cin >> t;
    while(t--)
        solve();
}
