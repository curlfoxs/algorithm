#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q;
ll x;

struct {
    struct {
        ll mn, s, lazy;
        bool mod=0;
    } seg[1<<19];
    /* update current node when accessed */
    void eval(int i, ll x, bool mod, int l, int r) {
        // if(l==3 && r==3) cout << seg[i].mn << " " << seg[i].mod << endl;
        if(mod) { // increase-to mod
            seg[i].mn=0;
            seg[i].s=0;
        }
        // update
        seg[i].mn+=x;
        seg[i].s+=x*(r-l+1);
        // clear lazy info
        seg[i].lazy=0;
        seg[i].mod=0;
    }
    /* push child to lazy propation, update it just when accessed */
    void push(int i, ll x, bool mod) {
        if(mod) {
            seg[i].lazy=0;
            seg[i].mod=mod; /* Significant BUG */
        }
        // pending to lazy propation
        seg[i].lazy+=x;
    }
    /* evaluate current node */
    void app(int i, ll x, bool mod, int l,  int r) {
        if(x>0) { /* Significant BUG: Nedd to detect whether need lazy update */
        // cout << l << "," << r << " : "  << x << " " << mod << endl;
            /* update current node when accessed */
            eval(i, x, mod, l, r);
            /* push child to lazy propation, update it just when accessed */
            if(l!=r) {
                push(2*i+1, x, mod);
                push(2*i+2, x, mod);
            }
        }
    }
    void upd(int lb, int rb, ll x, bool mod, int i=0, int l=0, int r=n-1) {
        // if exist needed lazy evaluation (Ask: seg[i].lazy>0?) when required;
        app(i, seg[i].lazy, seg[i].mod, l, r); /* Significant BUG: long long x parameter , or will overflow, Becuaxe seg[i].lazy will sum continuely */

        // no overlap;
        if(lb>r||rb<l) {
            // cout << l << "," << r << " " << seg[i].s << endl;
            return;
        }

        // total overlap
        if(lb<=l&&rb>=r) {
            app(i, x, mod, l, r);
            // cout << l << "," << r << " " << seg[i].s << endl;
            return;
        }
        // partial overlap;
        int mid=(l+r)/2;
        upd(lb, rb, x, mod, 2*i+1, l, mid);
        upd(lb, rb, x, mod, 2*i+2, mid+1, r);
        seg[i].s=seg[2*i+1].s+seg[2*i+2].s;
        seg[i].mn=min(seg[2*i+1].mn, seg[2*i+2].mn);
        // cout << l << "," << r << " " << seg[i].s << endl;
    }

    ll qry(int lb, int rb, int i=0, int l=0, int r=n-1) {
        app(i, seg[i].lazy, seg[i].mod, l, r);

        // No overlap;
        if(lb>r||rb<l)
            return 0 ;
        // total overlap
        if(lb<=l&&rb>=r)
            return seg[i].s;
        // partial overlap
        int mid=(l+r)/2;
        return qry(lb, rb, 2*i+1, l, mid)+qry(lb, rb, 2*i+2, mid+1, r);
    }

} st;
// Let's write this code. And compared with william J
int main() {
    cin >> n >> q;
    for(int i=0; i<n; ++i)
        cin >> x, st.upd(i, i, x, 1);

    while(q--) {
        ll t, a, b, y;
        cin >> t;
        if(t==1||t==2) {
            cin >> a >> b >> y, --a, --b;
            t=(t==2)?1:0;
            st.upd(a, b, y, t);
        } else {
            cin >> a >> b, --a, --b;
            cout << (ll)st.qry(a, b) << endl;
        }
    }
}
