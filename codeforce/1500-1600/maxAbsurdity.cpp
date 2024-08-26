#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;

int n, k;
ll x[mxN];
ar<ll, 2> mx, lr[mxN+1], rr[mxN+1];//b{mx sum, idx}

int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> x[i];
    ll s=0;
    //lr single sliding window
    for(int i=0; i<k; ++i)
        s+=x[i];
    mx[0]=s, mx[1]=0;
    lr[k]=mx;
    for(int i=k; i<n-k; ++i) {
        s+=x[i], s-=x[i-k];
        if(s>mx[0]) {
            mx[0]=s, mx[1]=i-k+1;
        }
        lr[i+1]=mx;
    }

    // rr single sliding window
    s=0;
    for(int i=n-k; i<n; ++i)
        s+=x[i];
    mx[0]=s, mx[1]=n-k;
    rr[n-k]=mx;
    for(int i=n-k-1; i>=k; --i) {
        s+=x[i], s-=x[i+k];
        if(s>=mx[0]) {
            mx[0]=s, mx[1]=i;
        }
        rr[i]=mx;
    }
    // solution of the problem
    ar<ll, 3> ans;
    ans[0]=-1e18;
    for(int i=k; i<=n-k; ++i) {
        if(lr[i][0]+rr[i][0]>ans[0]) {
            ans[0]=lr[i][0]+rr[i][0];
            ans[1]=lr[i][1];
            ans[2]=rr[i][1];
        }
    }
    cout << ans[1]+1 << " " << ans[2]+1;
}
