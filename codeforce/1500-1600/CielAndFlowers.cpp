#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e9;

int r, g, b, mx=0;

int main() {
    cin >> r >> g >> b;
    // 0 mix flowers;
    mx=(r/3)+(g/3)+(b/3);
    // 1 mix flowers;
    if(min({r, g, b})>=1)
        mx=max(mx, 1+(r-1)/3+(g-1)/3+(b-1)/3);
    if(min({r, g, b})>=2)
        mx=max(mx, 2+(r-2)/3+(g-2)/3+(b-2)/3);
    cout << mx;
}
