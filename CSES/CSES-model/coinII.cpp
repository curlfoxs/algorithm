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
const int mxN=100, mxX=1e6;

int n, x, c[mxX];
ll dp[mxX+1];

int main() {
    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> c[i];
    dp[0]=1;
        for(int j=0; j<n; ++j)
    for(int i=1; i<=x; ++i)
            if(i>=c[j])
                dp[i]=(dp[i]+dp[i-c[j]])%M;
    cout << dp[x];
}
