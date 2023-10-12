#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e3, M=1e9+7;
int n, m;
ll ans=1;


struct {
    ll dp[mxN*mxN];
    int p[mxN*mxN];
    void init() {
        iota(p, p+n*m, 0);
        fill(dp, dp+n*m, 1);
    }
    int find(int x) {
        return (x^p[x])?p[x]=find(p[x]):x;
    }
    bool join(int x, int y) {
        if((x=find(x))==(y=find(y)))
            return false;
        p[x]=y;
        dp[y]=(dp[y]*dp[x])%M;
        return true;
    }
} d;
int main() {
    ifstream cin("cave.in");
    ofstream cout("cave.out");
    cin >> n >> m;
    vector<string> s(n);
    for(int i=0; i<n; ++i) {
        cin >> s[i];
        // cout << dp[i] << endl;
    }
    d.init();
    for(int i=n-2; ~i; --i) {
        for(int j=1; j<m-1; ++j) {
            if(s[i][j]=='#')
                continue;
            if(s[i][j+1]=='.')
                d.join(i*m+j, i*m+j+1);
            if(s[i+1][j]=='.')
                d.join((i+1)*m+j, i*m+j);
        }
       for(int j=1; j<m-1; ++j) {
            if(s[i+1][j]=='.'&&d.p[(i+1)*m+j]==(i+1)*m+j)
                ans=(ans*d.dp[(i+1)*m+j])%M;
            if(s[i][j]=='.'&&d.p[i*m+j]==i*m+j)
                d.dp[i*m+j]=(d.dp[i*m+j]+1)%M;
        }
    }
    cout << ans;
}
