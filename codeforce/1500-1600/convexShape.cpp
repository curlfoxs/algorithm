#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=50;

bool vis[mxN][mxN];
int n, m, di[4]={-1, 1, 0, 0}, dj[4]={0, 0, -1, 1};
string b[mxN];

bool e(int i, int j) {
    return (i>=0&&i<n&&j>=0&&j<m&&b[i][j]=='B');
}

void dfs(int i, int j, int k, bool c) {
    vis[i][j]=1;
    // not changed direction
    if(e(i+di[k], j+dj[k])) {
        dfs(i+di[k], j+dj[k], k, c);
    }
    // chagnge direction
    if(!c) {
        for(int l=0; l<4; ++l) {
            if(l!=k) {
                if(e(i+di[l], j+dj[l]))
                    dfs(i+di[l], j+dj[l], l, 1);
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i)
        cin >> b[i];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(b[i][j]=='B') {
                memset(vis, 0, sizeof(vis));
                vis[i][j]=1;
                for(int k=0; k<4; ++k) {
                    if(e(i+di[k], j+dj[k]))
                        dfs(i+di[k], j+dj[k], k, 0);
                }
                for(int k=0; k<n; ++k) {
                    for(int l=0; l<m; ++l) {
                        if(b[k][l]=='B'&&!vis[k][l]) {
                            cout << "NO";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "YES";
}
