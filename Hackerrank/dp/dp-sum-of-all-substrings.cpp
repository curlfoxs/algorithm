#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7;
int n;
string t;
ll dp[mxN];
int main() {
    cin >> t;
    n=t.size();
    dp[0]=t[0]-'0';
    for(int i=1; i<n; ++i) {
        ll d=t[i]-'0';
        dp[i]=(dp[i-1]*10%M+d*(i+1))%M;
    }
    ll ans=0;
    for(int i=0; i<n; ++i)
        ans=(ans+dp[i])%M;
    cout << ans;
}
