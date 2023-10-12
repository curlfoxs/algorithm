#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1.5e5;
int n, k, h[mxN], sum, mx, ans;

int main() {
    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> h[i];
    // sliding window
    for(int i=0; i<k; ++i)
        sum+=h[i];
    mx=sum, ans=0;
    sum-=h[0];
    for(int i=k; i<n; ++i) {
        sum+=h[i];
        if(sum<mx) {
            mx=sum;
            ans=i-k+1;
        }
        sum-=h[i-k+1];
    }
    cout << ans+1;
}
