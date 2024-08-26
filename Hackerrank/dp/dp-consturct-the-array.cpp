#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, mxK=2e5, M=1e9+7;
int n, k, x;
ll dx[mxN], dnx[mxN];
int main() {
    cin >> n >> k >> x;
    if(x^1)
        dx[1]=1, dnx[1]=k-2;
    else
        dx[1]=0, dnx[1]=k-1;
    for(int i=2; i<n; ++i) {
        dx[i]=dnx[i-1];
        dnx[i]=((k-1)*dx[i-1])%M+((k-2)*dnx[i-1])%M;
    }
    cout << dx[n-1];
}
