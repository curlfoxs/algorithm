#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q;
ll x;

struct {
    ll mn, s, lazy;
    bool mod=0;
} sg[1<<19];
void app(ll x, ll mod, int i, int l, int r) {
    if(mod) { // Increase-To mod
        sg[i].mn=0;
        sg[i].s=0;
        sg[i].lazy=0;
        sg[i].mod=1;
    }
    // Update
    sg[i].mn+=x;
    sg[i].s+=x*(r-l+1);
    sg[i].lazy+=x;
}
void psh(int i, int l, int r) {
    if(!sg[i].lazy)
        return;
    int mid=(l+r)/2;
    app(sg[i].lazy, sg[i].mod, 2*i, l, mid);
    app(sg[i].lazy, sg[i].mod, 2*i+1, mid+1, r);
    sg[i].lazy=0;
    sg[i].mod=0;
}

void upd(int lb, int rb, ll x, bool mod, int i=1, int l=0, int r=n-1) {
    // No Overlap;
    if(lb>r||rb<l) {
        return;
    }

    // Total Overlap
    if(lb<=l&&rb>=r) {
        app(x, mod, i, l, r);
        return;
    }
    // Lazy Propation : if exist needed lazy evaluation (propation to children here) (Ask: if sg[i].lazy>0, then propation to its children);
    psh(i, l, r); /* Significant BUG: long long x parameter , or will overflow, Becuaxe sg[i].lazy will sum continuely */
    // Partial Overlap;
    int mid=(l+r)/2;
    upd(lb, rb, x, mod, 2*i, l, mid);
    upd(lb, rb, x, mod, 2*i+1, mid+1, r);
    sg[i].s=sg[2*i].s+sg[2*i+1].s;
    sg[i].mn=min(sg[2*i].mn, sg[2*i+1].mn);
    // cout << l << "," << r << " " << sg[i].s << endl;
}

ll qry(int lb, int rb, int i=1, int l=0, int r=n-1) {
    // No Overlap;
    if(lb>r||rb<l)
        return 0 ;
    // Total Overlap
    if(lb<=l&&rb>=r)
        return sg[i].s;
    // partial overlap
    int mid=(l+r)/2;
    psh(i, l, r); /* Significant BUG: long long x parameter , or will overflow, Becuaxe sg[i].lazy will sum continuely */
    return qry(lb, rb, 2*i, l, mid)+qry(lb, rb, 2*i+1, mid+1, r);
}

// Let's write this code. And compared with william J
int main() {
    cin >> n >> q;
    for(int i=0; i<n; ++i)
        cin >> x, upd(i, i, x, 1);

    while(q--) {
        ll t, a, b, y;
        cin >> t;
        if(t==1||t==2) {
            cin >> a >> b >> y, --a, --b;
            t=(t==2)?1:0;
            upd(a, b, y, t);
        } else {
            cin >> a >> b, --a, --b;
            cout << (ll)qry(a, b) << endl;
        }
    }
}
