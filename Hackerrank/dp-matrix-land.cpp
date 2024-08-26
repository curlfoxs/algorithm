#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=4e6;
int n, m;
int dp[mxN];
struct {
    int rt[mxN];
    int p[mxN];
    int v[mxN];
    void gen(int x, int val) {
        p[x]=x;
        v[x]=val;
    }
    int val(int x) {
        return v[find(x)];
    }
    int find(int x) {
        return (x^p[x])?p[x]=find(p[x]):x;
    }
    bool join(int x, int y) {
        if((x=find(x))==(y=find(y)))
            return false;
        p[x]=y;
        v[y]=v[y]+v[x];
        return true;
    }
} dsu;

int row (int x) {
    return x/m;
}
int col (int x) {
    return x-x/m*m;
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            int x;
            cin >> x;
            // cout << x << " ";
            dsu.gen(i*m+j, x);
            // cout << dsu.val(i*m+j) << " ";
            if(j>0&&dsu.val(i*m+j-1)>=0) {
                dsu.join(i*m+j, i*m+j-1);
                // cout << i << ", " << j << ": " << dsu.val(i*m+j) << endl;
            }
        }
    }
    int s=0, t=n*m-1;
    for(int i=0; i<n*m; ++i) {
        dp[i]=INT_MIN;
        if(row(i)==0)
            dp[dsu.find(i)]=max(dp[dsu.find(i)], dsu.val(i)); // from root
        else
            dp[dsu.find(i)]=max(dp[dsu.find(i)], dsu.val(i)+dp[dsu.find((row(i)-1)*m+col(i))]); // from root
        if(col(i)>0&&dsu.find(i)!=dsu.find(i-1)) { // merge two different set
            dp[dsu.find(i)]=max(dp[dsu.find(i)], dsu.v[dsu.find(i)]+dp[dsu.find(i-1)]);
            dp[dsu.find(i-1)]=max(dp[dsu.find(i-1)], dp[dsu.find(i)]);
        }
        // cout << "row: " << row(i) << " col: " << col(i)  << " " << dp[dsu.find(i)] <<endl;
    }
    int ans=INT_MIN;
    for(int i=n*m-1, c=0; c<m; --i, ++c)
        ans=max(ans, dp[dsu.find(i)]);
    cout << ans ;
}
