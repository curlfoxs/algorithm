#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=3e3;

int n, m;
ll d[mxN];
bool vis[mxN];
vector<ar<ll, 2>> adj[mxN];

int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    int s;
    cin >> s, --s;
    memset(d, 0x3f, sizeof(d));
    d[s]=0;
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq; // {distance, target}
    pq.push({0, s});
    while(pq.size()) {
        ar<ll, 2> u=pq.top();
        pq.pop();
        vis[u[1]]=1;
        for(ar<ll, 2> v : adj[u[1]]) {
            if(vis[v[1]])
                continue;
            if(d[v[1]]>v[0]) {
                d[v[1]]=v[0];
                pq.push({d[v[1]], v[1]});
            }
        }
    }
    int ans=0;
    for(int i=0; i<n; ++i) {
        // cout << i+1 << ": " << d[i] << endl;
        ans+=d[i];
    }
    cout << ans;
 }
