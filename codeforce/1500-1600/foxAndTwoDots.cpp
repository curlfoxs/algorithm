#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=50;

bool vis[mxN][mxN];
int n, m, di[4]={-1, 1, 0, 0}, dj[4]={0, 0, -1, 1};
char color[mxN][mxN];

bool e(int ni, int nj, int i, int j) {
    return ni>=0&&ni<n&&nj>=0&&nj<m&&color[ni][nj]==color[i][j];
}
void dfs(int i, int j, int pi=-1, int pj=-1) {
    vis[i][j]=1;
    // up, down, left, right
    for(int k=0; k<4; ++k) {
        int ni=i+di[k], nj=j+dj[k];
        if(ni==pi&&nj==pj)
            continue;
        if(e(ni, nj, i, j)) {
            if(vis[ni][nj]) {
                cout << "Yes";
                exit(0);
            }
            dfs(ni, nj, i, j);
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); ++j)
            color[i][j]=s[j];
    }

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j)
            if(!vis[i][j])
                dfs(i, j);
    }
    cout << "No";
}
