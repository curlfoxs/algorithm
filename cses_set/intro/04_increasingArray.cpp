#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    long long a, b, ans=0;
    for(int i=0; i<n; ++i) {
        b=a;
        cin >> a;
        if(i==0)
            continue;
        if(b>a) {
            ans+=(b-a);
            a=b;
        }
    }
    cout << ans;
}
