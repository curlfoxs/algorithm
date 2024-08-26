#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN=1e5;

int n, q, dt;
int ds[mxN], de[mxN];
ll sg[6*mxN], lazy[6*mxN];
set<ar<int, 2>> cs[mxN];
vector<int> adj[mxN];

void app(int x, int i, int l, int r) {
    sg[i]+=x*(r-l+1);
    lazy[i]+=x;
}
void psh(int i, int l, int r) {
    int mid=(l+r)/2;
    app(lazy[i], 2*i, l, mid);
    app(lazy[i], 2*i+1, mid+1, r);
    lazy[i]=0;
}

void upd(int lb, int rb, int x, int i=1, int l=0, int r=n-1)  {
    if(lb>r||rb<l)
        return ;
    if(lb<=l&&rb>=r) {
        app(x, i, l, r);
        return;
    }
    psh(i, l, r);
    int mid=(l+r)/2;
    upd(lb, rb, x, 2*i, l, mid);
    upd(lb, rb, x, 2*i+1, mid+1, r);
    sg[i]=sg[2*i]+sg[2*i+1];
}

ll qry(int lb, int rb, int i=1, int l=0, int r=n-1) {
    if(lb>r||rb<l)
        return 0;
    if(lb<=l&&rb>=r)
        return sg[i];
    psh(i, l, r);
    int mid=(l+r)/2;
    return qry(lb, rb, 2*i, l, mid)+qry(lb, rb, 2*i+1, mid+1, r);
}
void dfs(int u=0, int p=-1) {
    ds[u]=dt++;
    for(int v : adj[u])
        if(v^p)
            dfs(v, u);
    de[u]=dt;
}

int main() {
    ifstream cin("snowcow.in");
    ofstream cout("snowcow.out");

    cin >> n >> q;
    for(int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    while(q--) {
        int t;
        cin >> t;
        if(t==1) {
            int x, c;
            cin >> x >> c, --x, --c;
            auto it=cs[c].upper_bound({ds[x], 0});
            if(it!=cs[c].begin()) {
                --it;
                if((*it)[1]>ds[x])
                    continue;
            }
            it=cs[c].lower_bound({ds[x], 0});
            while(it!=cs[c].end()&&(*it)[0]<de[x]) {
                upd((*it)[0], (*it)[1]-1, -1);
                it=cs[c].erase(it);
            }
            cs[c].insert({ds[x], de[x]});
            upd(ds[x], de[x]-1, 1);
        } else {
            int x;
            cin >> x, --x;
            cout << qry(ds[x], de[x]-1) << endl;
        }
    }
}
