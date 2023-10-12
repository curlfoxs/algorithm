#include <bits/stdc++.h>

using namespace std;

#define ll long long

void sol(ll q, ll l) {
    ll t=(ll)9*pow(10, l-1)*l;
    if(q<=t) {
        --q;
        string s=to_string((ll)pow(10, l-1)+q/l);
        cout << s[q%l] << endl;
    }
    else
        sol(q-t, l+1);
}
int main() {
    int n;
    cin >> n;
    while(n--) {
        ll q;
        cin >> q;
        sol(q, 1);
    }
}
