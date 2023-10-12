#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e2;
int n, a[mxN];
int gcd(int a, int b) {
    return (b)?gcd(b, a%b):a;
}
void solve() {
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
    int x=a[0];
    for(int i=1; i<n; ++i) {
        x=gcd(x, a[i]);
        if(x==1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}
