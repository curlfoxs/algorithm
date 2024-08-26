#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e4;
int n, t, a[mxN];

void solve() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    ll mn=*min_element(a, a+n);
    ll mx=-1e18;
    vector<ll> diff(n);
    for(int i=0; i<n; ++i)
        diff[i]=a[i]-mn, mx=max(mx, diff[i]);
    mx+=4;
    vector<ll> dp(mx+1, 1e18);
    dp[0]=0;
    for(int c : {1, 2, 5}) {
        for(int j=c; j<=mx; ++j)
            dp[j]=min(dp[j], 1+dp[j-c]);
    }

    vector<ll> ans(5, 0);
    for(int i=0; i<n; ++i)
        for(int j=0; j<=4; ++j)
            ans[j]+=dp[diff[i]+j];
    cout << (*min_element(ans.begin(), ans.end())) << endl;
}
int main() {
    cin >> t;
    while(t--)
        solve();
}
