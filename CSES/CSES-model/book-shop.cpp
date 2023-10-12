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
const int mxN=1e3, mxX=1e5;

int n, x, h[mxN], s[mxN]; // s:page, h:price  x:most price
ll dp[mxX+1];

int main() {
    cin >> n >> x;
    for(int i=0; i<n; ++i)
        cin >> h[i];
    for(int i=0; i<n; ++i)
        cin >> s[i];

    dp[0]=0;
    for(int i=0; i<n; ++i) {
        for(int j=x; j>=h[i]; --j) {
            dp[j]=max(dp[j], s[i]+dp[j-h[i]]);
        }
    }
    cout << dp[x];
}
