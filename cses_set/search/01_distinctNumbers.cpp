#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;

int main() {
	int n, x;
	set<int> s;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		s.insert(x);
	}
	cout << s.size();
}
