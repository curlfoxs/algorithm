#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e3;

bool vis[mxN];
int n, m, val[mxN], ans;
vector<int> adj[mxN], tp;

void dfs(int u) {
    vis[u]=1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
    tp.push_back(u);
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> val[i];
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        if(val[a]<=val[b])
            adj[b].push_back(a);
        else
            adj[a].push_back(b);
    }

    for(int i=0; i<n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(tp.begin(), tp.end());
    for(int u : tp) {
        for(int v : adj[u])
            ans+=val[v];
    }
    cout << ans;
}
