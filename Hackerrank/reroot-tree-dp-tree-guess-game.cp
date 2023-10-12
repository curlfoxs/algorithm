#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int n, q, g, k, score=0;
int points[mxN];
set<ar<int, 2>> st;
vector<int> adj[mxN];

void dfs1(int u, int p=-1) {
    if(st.find({p, u})!=st.end())
        points[0]++;
    for(int v : adj[u]) {
        if(v==p)
            continue;
        dfs1(v, u);
    }
}

void dfs2(int u, int p=-1) {
    points[u]=(~p)?points[p]:points[0];
    if(st.find({p, u})!=st.end())
        points[u]--;
    if (st.find({u, p})!=st.end())
        points[u]++;
    if(points[u]>=k)
        score++;
    for(int v : adj[u]) {
        if(v==p)
            continue;
        dfs2(v, u);
    }
}

int gcd(int a, int b) {
    return b==0?a:gcd(b, a%b);
}

void solve() {
    cin >> n;
    for(int i=0; i<n; ++i)
        adj[i].clear();
    // Original Tree Graph
    for(int i=0; i<n-1; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> g >> k;
    st.clear();
    // Recored the Guess Edge to set
    for(int i=0; i<g; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;
        st.insert({a, b});
    }
    memset(points, 0, 4*n);
    score=0;
    dfs1(0);
    // cout << "points[0]: " << points[0] << endl;
    dfs2(0);
    // for(int i=0; i<n; ++i)
    //     cout << i+1 << "," << points[i] << endl;
    // Result and Output
    // cout << "de:"  << p << " " << total << endl;
    if(!score) {
        cout << 0 << "/" << 1 << endl;
        return;
    }
    int divisor=gcd(n, score);
    cout << score/divisor << "/" << n/divisor << endl;
}

int main() {
    cin >> q;
    for(int i=0; i<q; ++i) {
        solve();
    }
}
