#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, m;
int t[mxN];
multiset<int> h;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        int u;
        cin >> u;
        h.insert(u);
    }
    for(int i=0; i<m; ++i)
        cin >> t[i];


    for(int i=0; i<m; ++i) {
        auto it = h.upper_bound(t[i]);
        if(it==h.begin())
            cout << -1 << endl;
        else {
            cout << *(--it) << endl;
            h.erase(it);
        }
    }
}