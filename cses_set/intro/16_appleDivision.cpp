#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, a[20], mn, s, ps;

void dfs(int x) {
    mn=min(mn, abs(2*ps-s));
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

    // 遍历所有的子集，找出使得｜2x-10｜最小的子集便是这个问题的解
    mn=1e18;
    dfs(0);
    cout << mn;
}
