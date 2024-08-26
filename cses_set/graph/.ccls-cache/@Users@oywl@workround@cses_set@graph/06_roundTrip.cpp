#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;


bool cyc, vis[mxN];
int n, m, s, t, p[mxN];
vector<int> adj[mxN];

void dfs(int u, int pu=-1) {
    vis[u]=1;
    p[u]=pu;
    for(int v : adj[u]) {
        if(v==pu)
            continue;
        if(vis[v]) {
            if(!cyc) {
                vector<int> ans;
                int s=v, t=u;
                while(t!=s) {
                    ans.push_back(t);
                    t=p[t];
                }
                reverse(ans.begin(), ans.end());
                cout << ans.size()+2 << endl;
                cout << s+1 << " ";
                for(int a : ans)
                    cout << a+1 << " ";
                cout << s+1;
            }
            cyc=1;
            return;
        }
        dfs(v, u);
    }
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cyc=0;
    for(int i=0; i<n; ++i) {
        if(!vis[i])
            dfs(i);
    }
    if(!cyc)
        cout << "IMPOSSIBLE";
}
