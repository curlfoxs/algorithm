#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int n;
ll d[21], ans=0;

int countOne(ll mask) {
    int cnt=0;
    for(int i=0; i<64; ++i)
        if((mask>>i&1))
            ++cnt;
    return cnt;
}
void dfs(int n, int start, vector<ll> cur) {
    int cnt1=0;
    for(ll  a : cur) {
        // cout << a << " ";
        cnt1+=countOne(a); // Count 1's number -> 0's number is connected component
    }
    // cout << res << endl;
    // 1. 数字0的个数代表着多少个连通分量
    // 2. 相互分离(a&b==0)的cur里面的数代表着连通分量，因此cur.size()
    ans+=(64-cnt1)+cur.size(); // 0's reps component + Disjoin cur.size() component

    for(int i=start; i<n; ++i) {
        vector<ll> tmp(cur);
        bool ins=1;
        for(ll& mk : cur) {
            if(mk&d[i]) {
                mk|=d[i];
                ins =0;
                break;
            }
        }
        if(ins)
            cur.push_back(d[i]);
        dfs(n, i+1, cur);
        cur=tmp;
    }
}
int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> d[i];
    vector<ll> cur;
    dfs(n, 0, cur);
    cout << ans;
}
