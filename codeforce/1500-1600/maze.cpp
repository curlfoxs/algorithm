#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=500;


bool vis[mxN][mxN];
int n, m, s, k, c=0;
string b[mxN];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&b[i][j]=='.'&&!vis[i][j];
}

void dfs(int i, int j) {
    if(c==(s-k)) {
        return;
    }
    vis[i][j]=1;
    ++c;
    if(e(i-1, j))
        dfs(i-1, j);
    if(e(i+1, j))
        dfs(i+1, j);
    if(e(i, j-1))
        dfs(i, j-1);
    if(e(i, j+1))
        dfs(i, j+1);
}

int main() {
    cin >> n >> m >> k;
    for(int i=0; i<n; ++i)
        cin >> b[i];
    int si, sj;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(b[i][j]=='.'&&!vis[i][j]) {
                ++s, si=i, sj=j;
            }
        }
    }
    dfs(si, sj);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(b[i][j]=='.') {
                if(vis[i][j])
                    cout << '.';
                else
                    cout << 'X';
            } else {
                cout << '#';
            }
        }
        cout << endl;
    }
}
