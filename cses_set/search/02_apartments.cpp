#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int a[mxN], b[mxN];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i< n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i=0; i<m; i++) {
		cin >> b[i];
	}
	sort(b, b+m);

	int ap = 0, bp = 0, res=0;
	while (ap<n&&bp<m) {
		if (b[bp]>=a[ap]-k && b[bp]<=a[ap]+k){
			++res;
			++ap;
			++bp;
		} else if (a[ap]<=b[bp]) {
			++ap;
		} else {
			++bp;
		}
	}
	cout << res;
}
