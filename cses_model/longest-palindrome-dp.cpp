#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
string t;

int main() {
    cin >> t;
    int n=t.size();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    int ans=0, sp=0;
    for(int i=n-1; i>=0; --i) {
        for(int j=i; j<n; ++j) {
            if(t[i]==t[j]) {
                if(j-i<=1)
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i+1][j-1];
            }

            if(dp[i][j]) {
                if(j-i+1>ans) {
                    ans=j-i+1;
                    sp=i;
                }
            }
        }
    }

    cout << t.substr(sp, ans);
}
