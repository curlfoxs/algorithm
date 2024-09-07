#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m;
ll x;

struct {
    struct {
        ll mn, s, lazy, mxl, mxr, mxs;
        bool sub=0;
    } seg[1<<19];
    /* update current node when accessed */
    void eval(int i, ll x, bool sub, int l, int r) {
        // if(l==3 && r==3) cout << seg[i].mn << " " << seg[i].sub << endl;
        if(sub) { // increase-to sub
            seg[i].mn=0;
            seg[i].s=0;
        }
        // update
        seg[i].mn+=x;
        seg[i].s+=x*(r-l+1);
        // clear lazy info
        seg[i].lazy=0;
        seg[i].sub=0;
    }
    /* push child to lazy propation, update it just when accessed */
    void push(int i, ll x, bool sub) {
        if(sub) {
            seg[i].lazy=0;
            seg[i].sub=sub; /* Significant BUG */
        }
        // pending to lazy propation
        seg[i].lazy+=x;
    }
    /* evaluate current node */
    void app(int i, ll x, bool sub, int l,  int r) {
        if(x>0) { /* Significant BUG: Nedd to detect whether need lazy update */
        // cout << l << "," << r << " : "  << x << " " << sub << endl;
            /* update current node when accessed */
            eval(i, x, sub, l, r);
            /* push child to lazy propation, update it just when accessed */
            if(l!=r) {
                push(2*i+1, x, sub);
                push(2*i+2, x, sub);
            }
        }
    }
    void upd(int lb, int rb, ll x, bool sub=1, int i=0, int l=0, int r=n-1) {
        // if exist needed lazy evaluation (Ask: seg[i].lazy>0?) when required;
        app(i, seg[i].lazy, seg[i].sub, l, r); /* Significant BUG: long long x parameter , or will overflow, Becuaxe seg[i].lazy will sum continuely */

        // no overlap;
        if(lb>r||rb<l) {
            // cout << l << "," << r << " " << seg[i].s << endl;
            return;
        }

        // total overlap
        if(lb<=l&&rb>=r) {
            app(i, x, sub, l, r);
            return;
        }
        // partial overlap;
        int mid=(l+r)/2;
        upd(lb, rb, x, sub, 2*i+1, l, mid);
        upd(lb, rb, x, sub, 2*i+2, mid+1, r);
        seg[i].s=seg[2*i+1].s+seg[2*i+2].s;
        seg[i].mn=min(seg[2*i+1].mn, seg[2*i+2].mn);
    }

    /* Maximum subarray sum upd2() */
    void upd2(int lb, int rb, ll x, bool sub=1, int i=0, int l=0, int r=n-1) {
        // no overlap;
        if(lb>r||rb<l) {
            // cout << l << "," << r << " " << seg[i].s << endl;
            return;
        }

        // total overlap
        if(l==r&&lb<=l&&rb>=r) {
            seg[i].s=x;
            seg[i].mxs=x;
            seg[i].mxl=seg[i].mxr=x;
            return;
        }
        // partial overlap;
        int mid=(l+r)/2;
        upd2(lb, rb, x, sub, 2*i+1, l, mid);
        upd2(lb, rb, x, sub, 2*i+2, mid+1, r);
        seg[i].s=seg[2*i+1].s+seg[2*i+2].s;
        seg[i].mxs=max({seg[2*i+1].mxs, seg[2*i+2].mxs, seg[2*i+1].mxr+seg[2*i+2].mxl});
        seg[i].mxl=max({seg[2*i+1].mxl, seg[2*i+1].s+seg[2*i+2].mxl});
        seg[i].mxr=max({seg[2*i+2].mxr, seg[2*i+1].mxr+seg[2*i+2].s});
        // cout << l << "," << r << " " << seg[i].mxs << endl;
        // cout << l << "," << r << " " << seg[i].s << endl;
    }

    ll qry(int lb, int rb, int i=0, int l=0, int r=n-1) {
        app(i, seg[i].lazy, seg[i].sub, l, r);

        // No overlap;
        if(lb>r||rb<l)
            return 0 ;
        // total overlap
        if(lb<=l&&rb>=r)
            // return seg[i].s;
            return seg[i].mxs;
        // partial overlap
        int mid=(l+r)/2;
        // return qry(lb, rb, 2*i+1, l, mid)+qry(lb, rb, 2*i+2, mid+1, r);
        return max(qry(lb, rb, 2*i+1, l, mid), qry(lb, rb, 2*i+2, mid+1, r));
    }
} st;

// Let's write this code. And compared with william J
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> x, st.upd2(i, i, x);

    for(int i=0; i<m; ++i) {
        ll k, a;
        cin >> k >> a, --k;
        st.upd2(k, k, a);
        cout << max((ll)0, st.seg[0].mxs) << endl;
    }
}
