#include <bits/stdc++.h>
using namespace std;

#define ar array

const int mxN=1e2;

int n;
ar<int, 2> p[mxN];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        int a;
        cin >> a, --a;
        p[i][0]=a;
        p[i][1]=i;
    }
    sort(p, p+n);
    for(int i=0; i<n; ++i)
        cout << p[i][1]+1 << " ";
}
