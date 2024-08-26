#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q;
ll x[mxN];

struct {
    struct {
        ll mn, s, lazy;
    } seg[1<<19];
    /* update current node when accessed */
    void eval(int i, ll x, int l, int r) {
        // update
        seg[i].mn+=x;
        seg[i].s+=x*(r-l+1);
        // clear lazy info
        seg[i].lazy=0;
    }
    /* push child to lazy propation, update it just when accessed */
    void push(int i, ll x) {
        // pending to lazy propation
        seg[i].lazy+=x;
    }
    /* evaluate current node */
    void app(int i, ll x, int l,  int r) {
        if(x>0) { /* Significant BUG: Nedd to detect whether need lazy update */
            /* update current node when accessed */
            eval(i, x, l, r);
            /* push child to lazy propation, update it just when accessed */
            if(l!=r) {
                push(2*i+1, x);
                push(2*i+2, x);
            }
        }
    }
    void upd(int lb, int rb, ll x, int i=0, int l=0, int r=n-1) {
        // if exist needed lazy evaluation (Ask: seg[i].lazy>0?) when required;
        app(i, seg[i].lazy, l, r); /* Significant BUG: long long x parameter , or will overflow, Becuaxe seg[i].lazy will sum continuely */

        // no overlap;
        if(lb>r||rb<l) {
            return;
        }

        // total overlap
        if(lb<=l&&rb>=r) {
            app(i, x, l, r);
            return;
        }
        // partial overlap;
        int mid=(l+r)/2;
        upd(lb, rb, x, 2*i+1, l, mid);
        upd(lb, rb, x, 2*i+2, mid+1, r);
        seg[i].s=seg[2*i+1].s+seg[2*i+2].s;
        seg[i].mn=min(seg[2*i+1].mn, seg[2*i+2].mn);
    }

    ll qry(int lb, int rb, int i=0, int l=0, int r=n-1) {
        app(i, seg[i].lazy, l, r);

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
