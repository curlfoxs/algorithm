#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=2e3;

int n, m, k, d[mxN][1<<10];
vector<int> f[mxN];
vector<ar<int,2>> adj[mxN];

string rep(int mk) {
    string s;
    for(int i=9; ~i; --i) {
        if(mk&1<<i)
            s+="1";
        else
            s+="0";
    }
    return s;
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; ++i) {
        int t, A;
        cin >> t;
        while(t--) {
            cin >> A;
            f[i].push_back(A-1);
        }
    }
    for(int i=0; i<m; ++i) {
        int a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    memset(d, 0x3f, sizeof(d));
    int mask=0;
    for(int fish : f[0])
        mask|=(1<<fish);
    d[0][mask]=0;
    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq; // {distance, target, mask}
    pq.push({0, 0, mask});
    while(pq.size()) {
        ar<int, 3> u=pq.top();
        pq.pop();
        if(u[0]>d[u[1]][u[2]])
            continue;
        for(ar<int, 2> v : adj[u[1]]) {
            int mk=u[2];
            for(int fish : f[v[1]])
                mk|=(1<<fish);
            if(d[v[1]][mk]>u[0]+v[0]) {
                d[v[1]][mk]=u[0]+v[0];
                // cout << u[1] << "->" << v[1] << " " << d[v[1]][mk]  << " " << rep(mk) << endl;
                pq.push({d[v[1]][mk], v[1], mk});
            }
        }
    }
    int tm=0, t=n-1, ans=INT_MAX;
    for(int i=0; i<k; ++i)
        tm|=(1<<i);
    for(int i=0; i<(1<<k); ++i) {
        for(int j=0; j<(1<<k); ++j) {
            // cout << rep(i)<< " "  << rep(j) << " " << t << " " <<  d[t][i] << " " << d[t][j] << endl;
            if((i|j)==tm)
                ans=min(ans, max(d[t][i], d[t][j]));
        }
    }
    cout << ans << endl;
}
