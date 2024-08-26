#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=100, M=1e9+7;

ll ans=1;
int n, m, c[mxN];
string s[mxN];

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> s[i];
    for(int i=0; i<m; ++i) {
        set<char> gp;
        for(int j=0; j<n; ++j) {
            gp.insert(s[j][i]);
        }
        ans*=(ll)gp.size();
        ans%=M;
    }
    cout << ans;
}
