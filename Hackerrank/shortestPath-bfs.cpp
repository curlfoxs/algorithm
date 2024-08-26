#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;

int n, m, q, s;
bool vis[mxN];

int main() {
    cin >> q;
    while(q--) {
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for(int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b, --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cin >> s, --s;
        memset(vis, 0, sizeof(vis));
        vector<int> ans(n, -1);
        queue<int> qu;
        vis[s]=1;
        qu.push(s);
        int d=0;
        while(qu.size()) {
            int ns=qu.size();
            ++d;
            while(ns--) {
                int u=qu.front();
                qu.pop();
                for(int v : adj[u]) {
                    if(vis[v])
                        continue;
                    vis[v]=1;
                    qu.push(v);
                    ans[v]=d;
                }
            }
        }
        for(int i=0; i<n; ++i) {
            if(i==s)
                continue;
            if(~ans[i])
                ans[i]*=6;
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}
