#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7;
int n, N=0, cr=0;
vector<int> adj[mxN];
ll dp0[mxN], dp1[mxN]; // dp0: single root, dp1: belongs to one ally
void dfs(int u=0, int p=-1) {
    dp0[u]=dp1[u]=1;
    for(int v : adj[u]) {
        if(v^p) {
            dfs(v, u);
            dp0[u]=(dp0[u]*(dp0[v]+dp1[v]))%M;
            dp1[u]=(dp1[u]*dp1[v])%M;
        }
    }
    dp1[u]=(dp0[u]-dp1[u]+M)%M;
}
int main() {
    cin >> n;
    for(int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    cout << (dp1[0]*2%M);
}
