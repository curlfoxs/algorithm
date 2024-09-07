#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 2e5;
set<ar<ll, 2>> s;

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        s.insert({2*a, 1});
        s.insert({2*b+1, -1});
    }

    int cnt=0, ans=0;
    for (auto u : s) {
        cnt += u[1];
        ans=max(ans, cnt);
    }
    cout << ans;
}
