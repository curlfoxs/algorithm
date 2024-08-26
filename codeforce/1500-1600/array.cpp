#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int n, k, a[mxN];
map<int, int> mp;

int main() {
    cin >> n >> k;
    int lp=0, rp=0;
    for(int rp=0; rp<n; ++rp) {
        cin >> a[rp];
        mp[a[rp]]++;
        while(mp.size()==k) {
            mp[a[lp]]--;
            if(mp[a[lp]]==0) {
                cout << lp+1 << " " << rp+1;
                exit(0);
            }
            ++lp;
        }
    }
    cout << -1 << " " << -1;
}
