#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e4, mxQ=2e5;
int n, q, ans[mxQ], sg[4*mxN+1];
ar<int, 2> a[mxN]; // {value, original_index}
ar<int, 4> qr[mxQ]; // {k, start, end, original_index}
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
    sg[i]=sg[2*i]+sg[2*i+1];
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
    return qry(lb, rb, 2*i, l, mid)+qry(lb, rb, 2*i+1, mid+1, r);
}
// Let's write this code. And compared with william J
int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i][0], a[i][1]=i, upd(i, 1);
    cin >> q;
    for(int i=0; i<q; ++i) {
        cin >> qr[i][1] >> qr[i][2] >> qr[i][0], --qr[i][1], --qr[i][2];
        qr[i][3]=i;
    }
    sort(a, a+n);
    sort(qr, qr+q);
    int start=0;
    for(int i=0; i<q; ++i) {
        int k=qr[i][0], lb=qr[i][1], rb=qr[i][2],  ki=qr[i][3];
        int p=lower_bound(a, a+n, (ar<int, 2>){k+1, 0})-a;
        for(int j=start; j<min(p, n); ++j)
            upd(a[j][1], 0);
        start=p;
        ans[ki]=qry(lb, rb);
        // cout << "k: " << k << " ki: " << ki <<  " sorted_index: " << i << " ans: " << lb << ", " << rb << " : " << qry(lb, rb) << endl;
    }
    for(int i=0; i<q; ++i)
        cout << ans[i] <<endl;
}
