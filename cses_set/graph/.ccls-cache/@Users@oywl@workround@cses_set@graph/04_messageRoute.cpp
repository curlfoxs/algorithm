#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;


bool vis[mxN];
int n, m, p[mxN];
vector<int> adj[mxN];

int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> qu;
    vis[0]=1;
    qu.push(0);
    bool ok=0;
    while(qu.size()) {
        int u=qu.front();
        qu.pop();
        if(u==n-1) {
            ok=1;
            break;
        }
        for(int v : adj[u]) {
            if(vis[v])
                continue;
            vis[v]=1;
            p[v]=u;
            qu.push(v);
        }
    }
    if(!ok) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    int t=n-1;
    vector<int> ans;
    while(t!=0) {
        ans.push_back(t);
        t=p[t];
    }
    ans.push_back(t);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int a : ans)
        cout << a+1 << " ";
}
