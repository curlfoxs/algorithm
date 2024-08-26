#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;

int n, m, t;
bool vis[mxN];
map<int, int> latters, snakes;
int p[mxN];

void solve() {
    memset(vis, 0, sizeof(vis));
    latters.clear();
    snakes.clear();
    cin >> n;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        latters[a]=b;
    }
    cin >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        snakes[a]=b;
    }
    queue<int> qu;
    vis[0]=1;
    p[0]=-1;
    qu.push(0);
    bool ok=0;
    while(qu.size()) {
        int u=qu.front();
        qu.pop();
        if(u==99) {
            ok=1;
            break;
        }
        if(latters.find(u)!=latters.end()) {
            int v=latters[u];
            if(!vis[v]) {
                vis[v]=1;
                p[v]=u;
                qu.push(v);
            }
        } else if (snakes.find(u)!=snakes.end()) {
            int v=snakes[u];
            if(!vis[v]) {
                vis[v]=1;
                p[v]=u;
                qu.push(v);
            }
        } else {
            for(int i=6; i>=1; --i) {
                int v=u+i;
                if(v<100&&!vis[v]) {
                    vis[v]=1;
                    p[v]=u;
                    qu.push(v);
                }
            }
        }
    }
    int ans=0, t=99;
    while(~t) {
        // cout << t << "<-";
        t=p[t];
        ++ans;
        if(latters.count(t)||snakes.count(t))
            --ans;
    }
    if(ok)
        cout << ans-1 << endl;
    else
        cout << -1 << endl;
}

int main() {
    cin >> t;
    while(t--) {
        solve();
    }
}
