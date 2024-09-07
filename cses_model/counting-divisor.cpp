#include <bits/stdc++.h>
#define ar array
#define ll long long 
using namespace std;
const int mxN=1e5, mxA=1e6;

int n, x, lpf[mxA+1];
vector<int> pf;

int main() {
    for(int i=2; i<=mxA; ++i) {
        if(!lpf[i]) {
            pf.push_back(i);
            lpf[i]=i;
        }
        for(int j=0; j<pf.size()&&pf[j]<=lpf[i]&&i*pf[j]<=mxA; ++j) {
            lpf[i*pf[j]]=pf[j];
        }
    }

    vector<int> ans;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> x;
        map<int, int> mp;
        while(x^1) {
            mp[lpf[x]]++;
            x/=lpf[x];
        }
        int a=1;
        for(auto m : mp)
            a*=(m.second+1);
        ans.push_back(a);
    }
    for(int a : ans)
        cout << a << endl;
}
