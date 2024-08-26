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

const int mxN=100, mxX=1e6, M=1e9;

int n, x, c;
ll dp[mxX+1];

int main() {
    cin >> n >> x;
    dp[0]=0;
    for(int i=1; i<=x; ++i)
        dp[i]=1e9;
    for(int i=0; i<n; ++i) {
        cin >> c;
        for(int j=1; j<=x; ++j)
            if(j>=c)
                dp[j]=min(dp[j], 1+dp[j-c]);
    }
    cout << (dp[x]==1e9?-1:dp[x]);

}
