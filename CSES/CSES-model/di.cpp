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
    dp[0]=1;
        for(int j=1; j<=n; ++j)
            for(int i=1; i<=min(6, j); ++i) // could allow {1+2, 2+1} -> permutation
                dp[j]=(dp[j]+dp[j-i])%M;
    cout << dp[n];
}
