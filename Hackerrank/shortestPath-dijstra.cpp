#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=3e3;

int n, m;
ll d[mxN];


void solve() {
    cin >> n >> m;
    vector<vector<ar<ll, 2>>> adj(n);
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
        if(u[0]>d[u[1]])
            continue;
        for(ar<ll, 2> v : adj[u[1]]) {
            if(d[v[1]]>u[0]+v[0]) {
                d[v[1]]=u[0]+v[0];
                // cout << u[1] << "->" << v[1] << " " << d[v[1]][mk]  << " " << rep(mk) << endl;
                pq.push({d[v[1]], v[1]});
            }
        }
    }
    for(int i=0; i<n; ++i) {
        if(i==s)
            continue;
        if(d[i]>1e18)
            cout << -1 << " ";
        else
            cout << d[i] << " ";
    }
    cout << endl;
 }

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}
