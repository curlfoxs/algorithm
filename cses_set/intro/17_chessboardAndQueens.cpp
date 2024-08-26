#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool c[8], b[15], d[15];
int ans;
string board[8];

void dfs(int x) {
    if(x==8) {
        ++ans;
        return;
    }
    for(int i=0; i<8; ++i) {
        if(c[i]||b[x+i]||d[7-x+i]||board[x][i]=='*')
            continue;
        c[i]=1; // colume
        b[x+i]=1; // 左对角线
        d[7-x+i]=1; // 右对角线
        dfs(x+1);
        d[7-x+i]=0;
        b[x+i]=0;
        c[i]=0;
    }
}
int main() {
    for(int i=0; i<8; ++i)
        cin >> board[i];
    dfs(0);
    cout << ans;
}
