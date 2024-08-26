#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;


bool vis[mxN];
int n, m;
vector<int> adj[mxN];

void dfs(int u) {
    vis[u]=1;
    for(int v : adj[u])
        if(!vis[v])
            dfs(v);
}
int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> v;
    for(int i=0; i<n; ++i) {
        if(!vis[i]) {
            if(i!=0)
                v.push_back(i);
            dfs(i);
        }
    }
    cout << v.size() << endl;
    for(int a : v)
        cout << 1 << " " << a+1 << endl;
}
