#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e6;

bool f[mxN+1];

int main() {
    ll n, n1=0;
    cin >> n;
    ll s=n*(1+n)/2;
    if(s&1) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;

    s/=2;
    for(int i=n; i&&s; --i) {
        if(s>=i)
            f[i]=1, s-=i, ++n1;
    }
    cout << n1 << endl;
    for(int i=1; i<=n; ++i)
        if(f[i])
            cout << i << " ";
    cout << endl;
    cout << n-n1 << endl;
    for(int i=1; i<=n; ++i)
        if(!f[i])
            cout << i << " ";
    cout << endl;
}
