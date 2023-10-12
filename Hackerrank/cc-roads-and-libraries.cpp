#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int n, m, q, c_lib, c_road;
vector<int> co;
bool vis[mxN];

void dfs(int u, vector<vector<int>>& adj) {
    vis[u]=1;
    for(int v : adj[u]) {
        if(!vis[v])
            dfs(v, adj);
    }
    co.push_back(u);
}
int main() {
    cin >> q;
    while(q--) {
        cin >> n >> m >> c_lib >> c_road;
        vector<vector<int>> adj(n);
        for(int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b, --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(c_lib<=c_road) {
            cout << (ll)n*c_lib << endl;
            continue;
        }
        ll ans=0;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i) {
            if(vis[i])
                continue;
            dfs(i, adj);
            ans+=c_lib+c_road*(co.size()-1);
            co.clear();
        }
        cout << ans << endl;
    }
}
