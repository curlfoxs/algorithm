#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 2e5;
ar<int, 2> r[mxN];

int main() {
	int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
		int a, b;
		cin >> a >> b;
		r[i] = {b, a};
    }
	sort(r, r+n);

	int ans=0, p=0;
	for(int i=0; i<n; ++i) {
		if (p<=r[i][1]) {
			++ans;
			p=r[i][0];
		}
	}
	cout << ans;
}
