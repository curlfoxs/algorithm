#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e6, M=1e9+7;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a>b)
            swap(a, b);
        int c=b-a;
        b-=2*c;
        a-=c;
        if(a<0||b<0||b%3!=0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
}
}
