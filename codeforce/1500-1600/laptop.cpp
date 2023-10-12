#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

ar<int, 2> a[mxN];
int main () {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i][0] >> a[i][1];
    sort(a, a+n);
    for(int i=0; i<n-1; ++i) {
        if(a[i][0]<a[i+1][0]&&a[i][1]>a[i+1][1]) {
            cout << "Happy Alex" <<endl;
            return 0;
        }
    }
    cout << "Poor Alex";
}
