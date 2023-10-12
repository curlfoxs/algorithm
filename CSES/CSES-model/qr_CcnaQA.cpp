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

const int mxN=2e5;

int n, m, p[mxN];
ll d[mxN];
vector<ar<ll, 2>> adj[mxN]; // {price, dst vertex}

int main() {
    cin >> n >> m;
    ll a, b, c;
    for(int i=0; i<m; ++i) {
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c, b});
    }

    memset(d, 0x3f, sizeof(d));
    d[0]=0;

    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(ar<ll, 2> j : adj[i]) {
                if(d[j[1]]>d[i]+j[0]) {
                    d[j[1]]=d[i]+j[0];
                    p[j[1]]=i;
                    if(k==n-1) {
                        cout << "YES" << endl;
                        int u=i;
                        for(int i=0; i<n; ++i)
                            u=p[u];
                        vector<int> ans;
                        int v=u;
                        ans.push_back(v);
                        v=p[v];
                        while(v^u) {
                            ans.push_back(v);
                            v=p[v];
                        }
                        ans.push_back(v);
                        reverse(ans.begin(), ans.end());
                        for(int a : ans)
                            cout << a+1 << " ";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO";
}
