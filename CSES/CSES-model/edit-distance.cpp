#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <array>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
#define ll long long
#define ar array

const int M=1e9+7;
const int mxN=5e3;

int n, m;
ll dp[mxN+1][mxN+1];
string s1, s2;
int main() {
    cin >> s1 >> s2;
    n=s1.size();
    m=s2.size();
    for(int i=0; i<=n; ++i)
        dp[i][0]=i;
    for(int j=0; j<=m; ++j)
        dp[0][j]=j;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            dp[i][j]=1e9;
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min({dp[i][j], 1+dp[i-1][j], 1+dp[i][j-1], 1+dp[i-1][j-1]});
        }
    }
    cout << dp[n][m];
}
