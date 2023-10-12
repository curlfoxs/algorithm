#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;

int n, m, a[mxN];
ll sum[mxN], dp[mxN], mx=-1e18;
vector<int> adj[mxN];

void dfs1(int u, int p=-1) {
    sum[u]=a[u];
    for(int v : adj[u]) {
        if(v==p)
            continue;
        dfs1(v, u);
        sum[u]+=sum[v];
        dp[u]+=dp[v]+sum[v];
    }
}

void dfs2(int u, int p=-1) {
    mx=max(mx, dp[u]);
    for(int v : adj[u]) {
        if(v==p)
            continue;
        ll dpu=(dp[u]-dp[v]-sum[v]);
        dp[v]+=dpu+(sum[u]-sum[v]);
        sum[v]=sum[u];
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    for(int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0);
    dfs2(0);
    cout << mx;
}
