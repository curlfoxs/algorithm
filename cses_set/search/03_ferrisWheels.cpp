#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int p[mxN];

int main() {
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> p[i];
    sort(p, p+n);

    int ans =0;
    int p1=0, p2=n-1;
    while(p1<p2) {
        while(p1<p2&&p[p1]+p[p2]>x)
            --p2, ++ans;
        if(p1<p2)
            ++p1, --p2, ++ans;
    }
    ans += (p1==p2);
    cout << ans;
}