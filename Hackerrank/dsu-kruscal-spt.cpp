#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;

int n, m, p[mxN];

int find(int x) {
    return p[x]=(x^p[x])?find(p[x]):x;
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y)))
        return false;
    p[x]=y;
    return true;
}

int main() {
    cin >> n >> m;
    priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq;
    for(int i=0; i<m; ++i) {
        int a, b ,c;
        cin >> a >> b >> c, --a, --b;
        pq.push({c, a, b});
    }
    iota(p, p+n, 0);
    int ans=0, cntEdge=0;
    while(pq.size()) {
        ar<int, 3> u=pq.top();
        pq.pop();
        if(join(u[1], u[2])) {
            ans+=u[0];
            // cout << u[1] << "," << u[2] << ","  << u[0] << endl;
            if(++cntEdge==n-1)
                break;
        }
    }
    cout << ans;
}
