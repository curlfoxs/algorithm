#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int tol[mxN], tor[mxN], a[mxN], n, q;

int main() {
    cin >> n >> q;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    tol[0]=0, tor[n-1]=n-1;
    for(int i=1; i<n; ++i) {
        if(a[i]<=a[i-1])
            tol[i]=tol[i-1];
        else
            tol[i]=i;
    }
    for(int i=n-2; i>=0; --i) {
        if(a[i]<=a[i+1])
            tor[i]=tor[i+1];
        else
            tor[i]=i;
    }
    // calculate tol[] and tor[]
    while(q--) {
        int l, r;
        cin >> l >> r, --l, --r;
        if(tol[r]<=tor[l])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
