#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, q;
ll x[mxN], sg[4*mxN];

void upd(int lb, int x, int i=1, int l=0, int r=n-1) {
    // no overlap;
    if(lb>r||lb<l)
        return;
    // total overlap;
    if(lb==l && lb==r) {
        sg[i]=x;
        return;
    }
    // partial overlap;
    int mid=(l+r)/2;
    upd(lb, x, 2*i, l, mid);
    upd(lb, x, 2*i+1, mid+1, r);
    sg[i]=sg[2*i]^sg[2*i+1];
}
ll qry(int lb, int rb, int i=1, int l=0, int r=n-1) {
    // No overlap;
    if(lb>r||rb<l)
        return 0;
    // total overlap
    if(lb<=l&&rb>=r)
        return sg[i];
    // partial overlap
    int mid=(l+r)/2;
    return qry(lb, rb, 2*i, l, mid)^qry(lb, rb, 2*i+1, mid+1, r);
}
// Let's write this code. And compared with william J
int main() {
    cin >> n >> q;
    for(int i=0; i<n; ++i)
        cin >> x[i], upd(i, x[i]);

    while(q--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        cout << qry(a, b) << endl;
    }
}
