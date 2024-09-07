#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 2e5;
int n;

int main() {
	ll ans=-1e18, p=0;
    cin >> n;
    for (int i=0; i<n; ++i) {
		ll a;
		cin >> a;
		p=(p>0) ? p+a : a;
		ans=max(ans, p);
	}
	cout << ans;
}
