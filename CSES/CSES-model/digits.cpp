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
const int mxN=1e6;

int n;
ll dp[mxN+1];

int main() {
    cin >> n;
    dp[0]=0;
    for(int i=1; i<=n; ++i) {
        dp[i]=1e9;
        for(int j=i; j; j/=10) {
            int d=j%10;
            dp[i]=min(dp[i], 1+dp[i-d]);
        }
    }
    cout << dp[n];
}
