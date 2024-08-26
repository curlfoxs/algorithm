#include <cmath>
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

const int mxN=2e5, P=30; // ceil(log2(10^9))
int n, q, up[mxN][P];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    for(int i=0; i<n; ++i)
        cin >> up[i][0], --up[i][0];
    for(int i=1; i<P; ++i) {
        for(int j=0; j<n; ++j)
            up[j][i]=up[up[j][i-1]][i-1];
    }
    while(q--) {
        int s, k;
        cin >> s >> k, --s;
        int ans=s;
        for(int i=0; i<P; ++i)
            if(1&(k>>i))
                ans=up[ans][i];
        cout << ans+1 << endl;
    }
}
