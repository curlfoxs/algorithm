#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

const int mxN=2e5;
int n, q, t[mxN], rt[mxN], ccr[mxN], ci[mxN], cs[mxN], d[mxN], ds[mxN], de[mxN], dt;
vector<int> adj[mxN], cyc;
bool vis[mxN];

void dfs(int u) {
    ds[u]=dt++;
    for(int v : adj[u]) {
        if(v^rt[v]) {
            rt[v]=rt[u];
            ccr[v]=ccr[u];
            d[v]=d[u]+1;
        }
    }
    de[u]=dt;
}

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> t[i], --t[i];
        adj[t[i]].push_back(i);
    }
    memset(rt, -1, sizeof(rt));
    for(int i=0; i<n; ++i) {
        if(rt[i]!=-1)
            continue;
        int u=i;
        while(!vis[u]) {
            vis[u]=1;
            u=t[u];
        }
        while(!cyc.size()||u^cyc[0]) {
            ci[u]=cyc.size();
            cyc.push_back(u);
            rt[u]=u;
            ccr[u]=i;
            u=t[u];
        }
        for(int c : cyc) {
            dt=0;
            dfs(c);
            cs[c]=cyc.size();
        }
        cyc.clear();
    }

    for(int i=0; i<n; ++i)
        cout << d[i]+cs[rt[i]] << endl;
}
