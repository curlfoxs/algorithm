#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN=2e5;

int n, c[mxN], dp[mxN];
vector<int> adj[mxN];

void dfs1(int u=0, int p=-1) {
    dp[u]=(c[u])?1:-1;
    for(int v : adj[u]) {
        if(v^p) {
            dfs1(v, u);
            if(dp[v]>0)
                dp[u]+=dp[v];
        }
    }
}

void dfs2(int u=0, int p=-1) {
    if(~p) {
        dp[u]=max(dp[u], dp[p]+(dp[u]<0?dp[u]:0));
    }
    for(int v : adj[u])
        if(v^p)
            dfs2(v, u);
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> c[i];
    for(int i=1; i<n; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1();
    dfs2();
    for(int i=0; i<n; ++i)
        cout << dp[i] << " ";
}
