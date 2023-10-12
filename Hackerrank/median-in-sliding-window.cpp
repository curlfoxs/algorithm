#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, d, a[mxN], ans=0;
ll sg [6*201];

void upd(int lb, int x, int i=1, int l=0, int r=200) {
    // no overlap;
    if(lb>r||lb<l)
        return;
    // total overlap;
    if(lb==l && lb==r) {
        sg[i]+=x;
        return;
    }
    // partial overlap;
    int mid=(l+r)/2;
    upd(lb, x, 2*i, l, mid);
    upd(lb, x, 2*i+1, mid+1, r);
    sg[i]=sg[2*i]+sg[2*i+1];
}
ll qry(int lb, int rb, int i=1, int l=0, int r=200) {
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

int find(int x) {
    int lb=0, rb=200;
    while(lb<=rb) {
        int mb=(lb+rb)/2;
        if(qry(0, mb)<=x)
            lb=mb+1;
        else
            rb=mb-1;
    }
    return lb;
}

int main() {
    cin >> n >> d;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int x, y;
    if(d&1)
        x=y=d/2;
    else {
        x=d/2-1;
        y=d/2;
    }
    for(int i=0; i<d; ++i)
        upd(a[i], 1);
    for(int i=d; i<n; ++i) {
        upd(a[i], 1);
        int m1=find(x);
        int m2=find(y);
        // cout << "i: " << i << " m1: " << m1 << " m2: " << m2 << " a[i]: " << a[i] << endl;
        // for(int j=0; j<=200; ++j) {
        //     int z=qry(j, j);
        //     if(z>0)
        //         cout << "j: " << j << " : " << z << endl;
        // }

        if(a[i]>=m1+m2)
            ++ans;
        upd(a[i-d], -1);
    }
    cout << ans;
}
