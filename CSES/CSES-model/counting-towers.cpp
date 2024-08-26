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

int n, t, q[100];
ll dp1[mxN+1], dp2[mxN+1]; // all possible way use long long type

int main() {
    cin >> t;
    for(int i=0; i<t; ++i) {
        cin >> q[i];
        n=max(n, q[i]);
    }
    dp1[1]=1; // last row: width 1
    dp2[1]=1; // last row: width 2
    for(int i=2; i<=n; ++i) {
        dp1[i]=(4*dp1[i-1] + dp2[i-1])%M;
        dp2[i]=(dp1[i-1] + 2*dp2[i-1])%M;
    }
    for(int i=0; i<t; ++i)
        cout << ((dp1[q[i]]+dp2[q[i]])%M) << endl;
}
