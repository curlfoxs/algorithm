#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

const int mxA=1e6; // 1e6的 O(n)是不会超时的

int c[mxA+1]; // 记录各数的频率

void solve() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int x;
        cin >> x;
        ++c[x];
    }
    for(int i=mxA; i; --i) { // 从大到小往后找
        int d=0;
        for(int j=i; j<=mxA; j+=i)
            d+=c[j];
        if(d>1) { // 如果 i*n 能组成多个(>=2)数，那么它就是公共因数
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}
