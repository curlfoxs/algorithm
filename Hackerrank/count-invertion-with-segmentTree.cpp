#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define  ar array

const int mxN=1e5;

int t, n, a[mxN], mx=INT_MIN;
vector<ll> sg;

void upd(int lb, int x, int i=1, int l=0, int r=mx) {
    if(lb<l || lb>r)
        return ;
    if(lb==l&&lb==r) {
        sg[i]+=x;
        return;
    }
    int mid=(l+r)/2;
    upd(lb, x, 2*i, l, mid);
    upd(lb, x, 2*i+1, mid+1, r);
    sg[i]=sg[2*i]+sg[2*i+1];
}

ll qry(int lb, int rb, int i=1, int l=0, int r=mx) {
    if(lb>r||rb<l)
        return 0;
    if(lb<=l&&rb>=r)
        return sg[i];
    int mid=(l+r)/2;
    return qry(lb, rb, 2*i, l, mid)+qry(lb, rb, 2*i+1, mid+1, r);
}

void solve() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i], mx=max(mx, a[i]);
    ll ans=0;
    sg.assign(4*mx, 0);
    for(int i=0; i<n; ++i) {
        ans+=qry(a[i]+1, mx);
        upd(a[i], 1);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
        solve();
}
