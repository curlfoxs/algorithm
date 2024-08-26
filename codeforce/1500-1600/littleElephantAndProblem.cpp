#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;

int n, a[mxN];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    int x, y;
    for(y=n-1; y>=0; --y) {
        if(y&&a[y]<a[y-1])
            break;
    }
    while(y>=0&&y<n-1&&a[y]==a[y+1])
        ++y;
    for(x=0; x<n; ++x) {
        if(x<n-1&&a[x]>a[x+1])
            break;
    }
    while(x>0&&x<n&&a[x]==a[x-1])
        --x;
    if(y!=-1&&x!=n) {
        swap(a[x], a[y]);
    }
    for(int i=0; i<n-1; ++i) {
        if(a[i]>a[i+1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
