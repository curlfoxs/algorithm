#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

int n;
int b[100];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> b[i];
    int mx=INT_MIN, lp=0, rp=n-1;
    for(int i=0; i<n; ++i) {
        int zc=0;
        for(int j=i; j<n; ++j) {
            if(b[j]==0)
                ++zc;
            if((2*zc-(j-i+1))>mx) {
                mx=2*zc-(j-i+1);
                lp=i, rp=j;
            }
        }
    }

    for(int i=lp; i<=rp; ++i)
        b[i]=1-b[i];
    int ans=0;
    for(int i=0; i<n; ++i)
        if(b[i]==1)
            ++ans;
    cout << ans;
}
