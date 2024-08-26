#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;


bool vis[mxN];
int n, m;
ll c[mxN], cc, mn, cmn;
vector<int> st, adj1[mxN], adj2[mxN];
vector<ar<ll, 3>> ans;

void dfs1(int u) {
    vis[u]=1;
    for(int v : adj1[u])
        if(!vis[v])
            dfs1(v);
    st.push_back(u);
}

void dfs2(int u) {
    vis[u]=1;
    for(int v : adj2[u])
        if(!vis[v])
            dfs2(v);
    ++cc;
    if(c[u]==mn)
        ++cmn;
    else if(c[u]<mn) {
        mn=c[u];
        cmn=1;
    }
}
int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> c[i];
    cin >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }

    // 1st go through to build stack
    for(int i=0; i<n; ++i)
        if(!vis[i])
            dfs1(i);

    // 2st go through to find scc
    memset(vis, 0, sizeof(vis));
    for(int i=st.size()-1; i>=0; --i) {
        if(!vis[st[i]]) {
            cc=0, mn=1e18, cmn=1;
            dfs2(st[i]);
            ans.push_back({cc, mn, cmn});
        }
    }
    ll price=0, ways=1;
    for(auto a : ans)
        price+=a[1], ways*=a[2], ways%=M;
    cout << price << " " << ways;
}
