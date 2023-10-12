#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
int n, q;
string t;
struct sg_node {
    ll olb, orb, mb; // {open left brackets, open right brackets, match brackets}
}sg[4*mxN];

sg_node operator+(sg_node lt, sg_node rt) {
    sg_node ret={};
    ll match=min(lt.olb, rt.orb);
    ret.mb+=lt.mb+rt.mb+2*match;
    ret.olb=(lt.olb-match)+rt.olb;
    ret.orb=lt.orb+(rt.orb-match);
    return ret;
}

void gen(int i=1, int l=0, int r=n-1) {
    /* Build the tree Once */
    if(l==r) {
        if(t[l]=='(')
            sg[i].olb=1;
        else if(t[l]==')')
            sg[i].orb=1;
        return;
    }
    // partial overlap;
    int mid=(l+r)/2;
    gen(2*i, l, mid);
    gen(2*i+1, mid+1, r);
    sg[i]=sg[2*i]+sg[2*i+1];
}

void upd(int lb, char x, int i=1, int l=0, int r=n-1) {
    /* One Node Update TLE */
    // no overlap;
    if(lb>r||lb<l)
        return;
    // total overlap;
    if(lb==l && lb==r) {
        if(x=='(')
            sg[i].olb=1;
        else if(x==')')
            sg[i].orb=1;
        return;
    }
    // partial overlap;
    int mid=(l+r)/2;
    upd(lb, x, 2*i, l, mid);
    upd(lb, x, 2*i+1, mid+1, r);
    sg[i]=sg[2*i]+sg[2*i+1];
}

sg_node qry(int lb, int rb, int i=1, int l=0, int r=n-1) {
    // No overlap;
    if(lb>r||rb<l)
        return {0, 0, 0};
    // total overlap
    if(lb<=l&&rb>=r)
        return sg[i];
    // partial overlap
    int mid=(l+r)/2;
    if(rb<=mid)
        return qry(lb, rb, 2*i, l, mid);
    if(lb>mid)
        return qry(lb, rb, 2*i+1, mid+1, r);
    return qry(lb, rb, 2*i, l, mid)+qry(lb, rb, 2*i+1, mid+1, r);
}

// Let's write this code. And compared with william J
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    n=t.size();
    for(int i=0; i<t.size(); ++i)
        upd(i, t[i]);
    // gen();
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        // cout << qry(a, b).olb << ", " << qry(a, b).orb << ", " << qry(a,b).mb << endl;
        cout << qry(a, b).mb <<endl;
    }
}
