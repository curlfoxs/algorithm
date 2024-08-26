#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

const int mxN=1e5;

int t, n, a[mxN];
ll ans;

void merge(int l1, int r1, int l2, int r2) {
    int cnt=r1-l1+1;
    vector<int> tp(cnt);
    for(int i=0; i<tp.size(); ++i)
        tp[i]=a[l1+i];
    int i=l1, j=l2, k=0;
    while(k<tp.size()&&j<=r2) {
        if(tp[k]<=a[j]) {
            a[i++]=tp[k++];
            cnt--;
        } else {
            a[i++]=a[j++];
            ans+=cnt;
        }
    }
    if(j<=r2) {
        while(j<=r2)
            a[i++]=a[j++];
    } else {
        while(k<tp.size())
            a[i++]=tp[k++];
    }
}

void msort(int l, int r) {
    if(l==r)
        return;
    int mid=(l+r)/2;
    msort(l, mid);
    msort(mid+1, r);
    merge(l, mid, mid+1, r);
}

void solve() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    ans=0;
    msort(0, n-1);
    cout << ans << endl;
}
int main() {
    cin >> t;
    while(t--)
        solve();
}
