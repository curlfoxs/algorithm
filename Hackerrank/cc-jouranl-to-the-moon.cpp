#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int n, m;
vector<int> adj[mxN], co, cs;
bool vis[mxN];

void dfs(int u) {
    vis[u]=1;
    for(int v : adj[u]) {
        if(!vis[v])
            dfs(v);
    }
    co.push_back(u);
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; ++i) {
        if(vis[i])
            continue;
        dfs(i);
        cs.push_back((int)co.size());
        co.clear();
    }
    ll ans=((ll)n*(n-1))/2;
    for(int i=0; i<cs.size(); ++i)
        ans-=((ll)cs[i]*(cs[i]-1))/2;
    cout << ans << endl;

}
