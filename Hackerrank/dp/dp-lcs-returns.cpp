#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=5e3;
int n, m, lcs, dp1[mxN+1][mxN+1], dp2[mxN+1][mxN+1];
string t, p;

void gen_dp() {
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(i)
                dp1[i][j]=max(dp1[i][j], dp1[i-1][j]);
            if(j)
                dp1[i][j]=max(dp1[i][j], dp1[i][j-1]);
            if(t[i]==p[j]) {
                if(!i||!j)
                    dp1[i][j]=1;
                else
                    dp1[i][j]=max(dp1[i][j], dp1[i-1][j-1]+1);
            }
        }
    }
    for(int i=n-1; i>=0; --i) {
        for(int j=m-1; j>=0; --j) {
            if(i<n-1)
                dp2[i][j]=max(dp2[i][j], dp2[i+1][j]);
            if(j<m-1)
                dp2[i][j]=max(dp2[i][j], dp2[i][j+1]);
            if(t[i]==p[j]) {
                if(i==n-1||j==m-1)
                    dp2[i][j]=1;
                else
                    dp2[i][j]=max(dp2[i][j], dp2[i+1][j+1]+1);
            }
        }
    }
}
int main() {
    cin >> t >> p;
    n=t.size(), m=p.size();
    map<int, vector<int>> mp;
    vector<char> candidate;
    for(char c='a'; c<='z'; ++c)
        candidate.push_back(c);
    for(char c='A'; c<='Z'; ++c)
        candidate.push_back(c);
    for(char c='0'; c<='9'; ++c)
        candidate.push_back(c);
    // Initialize
    gen_dp();
    lcs=dp1[n-1][m-1];
    for(int i=0; i<m; ++i)
        mp[p[i]].push_back(i);
    ll ans=0;
    for(int i=0; i<=n; ++i) {
        for(char ch : candidate) {
            if(mp.find(ch)==mp.end())
                continue;
            for(int idx : mp[ch]) {
                ll left=0, right=0;
                if(i&&idx)
                    left=dp1[i-1][idx-1];
                if(i<n&&idx<m-1)
                    right=dp2[i][idx+1];
                if(left+right==lcs) {
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans;
}
