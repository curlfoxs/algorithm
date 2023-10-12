#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=3e3;

int main() {
    int n;
    string t;
    cin >> n >> t;
    int m=n/4;
    map<char, int> mp;
    for(char ch : t)
        mp[ch]++;
    int ans=INT_MAX;
    for(int i=0, j=0; i<n; ++i) {
        while(j<n&&(mp['A']>m||mp['G']>m||mp['C']>m||mp['T']>m)) {
            mp[t[j]]--;
            ++j;
        }
        if(mp['A']<=m&&mp['G']<=m&&mp['C']<=m&&mp['T']<=m)
            ans=min(ans, j-i);
        mp[t[i]]++;
    }
    cout << ans;
}
