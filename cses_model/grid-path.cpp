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
const int mxN=1e3;
string s[mxN];
int n;
ll dp[mxN][mxN]; // all possible ways/path

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> s[i];
    dp[0][0]=1;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(i)
                dp[i][j]+=dp[i-1][j];
            if(j)
                dp[i][j]+=dp[i][j-1];
            dp[i][j]%=M;
            if(s[i][j]=='*')
                dp[i][j]=0;
        }
    }
    cout << dp[n-1][n-1];
}
