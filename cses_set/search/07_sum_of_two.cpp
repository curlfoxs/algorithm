#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 2e5;
map<int, int> m;

int main() {
    int n, x;
    cin >> n >> x;
    for (int i=0; i<n; ++i) {
		int a;
		cin >> a;
		if (m.find(x-a) != m.end()) {
			cout << m[x-a]+1 << " " << i+1;
			return 0;
		}
		m[a]=i;
    }
	cout << "IMPOSSIBLE";
}
