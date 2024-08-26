#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, a[20], mn, s, ps;
vector<ll> subSet;

void dfs(int x) {
    mn=min(mn, ps);
    if(x>=n)
        return;
    for(int i=x; i<n; ++i) {
        ps+=a[i];
        dfs(i+1);
        ps-=a[i];
    }
}
int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i], s+=a[i];

    mn=-1e18;
    dfs(0);
}
