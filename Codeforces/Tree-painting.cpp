#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN=2e5;

int n;
ll cnt[mxN], points[mxN], ans=0;
vector<int> adj[mxN];

void dfs1(int u=0, int p=-1) {
    points[u]=0;
    cnt[u]=1;
    for(int v : adj[u]) {
        if(v^p) {
            dfs1(v, u);
            cnt[u]+=cnt[v];
            points[u]+=points[v];
        }
    }
    points[u]+=cnt[u];
}

void dfs2(int u=0, int p=-1) {
    if(~p) {
        points[u]=points[p]-cnt[u]+cnt[p]-cnt[u];
        cnt[u]=cnt[p];
    }
    ans=max(ans, points[u]);
    for(int v : adj[u])
        if(v^p)
            dfs2(v, u);
}
int main() {
    cin >> n;
    for(int i=1; i<n; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1();
    dfs2();
    cout << ans;
}
