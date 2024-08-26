#include <bits/stdc++.h>
using namespace std;

#define ll long long

// my main function
int main() {
    string s;
    cin >> s;
    char c=s[0];
    ll a=1, ans=1;
    for(int i=1; i<s.length(); ++i) {
        if(s[i]!=c) {
            a=1;
        } else {
            a+=1;
        }
        ans=max(ans, a);
        c=s[i];
    }
    cout << ans;
}
