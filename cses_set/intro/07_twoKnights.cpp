#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;
    for(int k=1; k<=n; ++k) {
        ll a=k*k, b=a*(a-1)/2;
        if(k>=2)
            b-=4*(k-2)*(k-1);
        cout << b << endl;
    }
}
