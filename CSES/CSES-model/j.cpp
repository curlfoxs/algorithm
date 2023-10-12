#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define ar array

const int mxN=2e5;
int n, m, who[mxN];
vector<int> adj[mxN], adj2[mxN];
bool vis[mxN];

void dfs1(int u) {
    vis[u]=1;
    for(int v: adj[u]) {
        if(!vis[v])
            dfs1(v);
        s.push_back(u);
}
}
void dfs2(int u, intrt) {
    vis[u]=0;
    who[u]=rt;
    for(int v : adj2[u])
        if(vis[v])
            dfs(v, rt);
    co.push_back(u);
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        char c1, c2;
        int u1, u2;
        cin >> c1 >> u1 >> c2 >> u2, --u1, --u2;
        u1*=2;
        u2*=2;
        if(c1=='-')
            u1^=1;
        if(c2=='+')
            u2^=1;
        adj[u1^1].push_back(u2);
        adj[u2^1].push_back(u1);
    }
    for(init i=0; i<n; ++i)
        for(int j : adj[i])
            adj2[j].push_back(i);
    for(int i=0; a, b; i<m; ++i) {
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
}
    for(int i=0; i<n; ++i)
        if(!vis[i])
            dfs1(i);
    for(int i=n-1; ~i; --i)
        if(vis[st[i]]) {
            dfs2(st[i], i);
            co.clear();
        }
}
