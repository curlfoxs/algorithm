#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool vis[7][7];
int ans;
string s;

bool e(int x, int y) {
    return x>=0&&x<=6&&y>=0&&y<=6&&!vis[x][y];
}

void dfs(int x, int y, int c=0) {
    if(x==6&&y==0) {
        if(c==48)
            ++ans;
        return;
    }
    vis[x][y]=1;
    if((s[c]=='?'||s[c]=='L')&&e(x, y-1)) {
        if(!(!e(x, y-2)&&e(x-1, y-1)&&e(x+1, y-1)))
        dfs(x, y-1, c+1);
    }
    if((s[c]=='?'||s[c]=='R')&&e(x, y+1)) {
        if(!(!e(x, y+2)&&e(x-1, y+1)&&e(x+1, y+1)))
        dfs(x, y+1, c+1);
    }
    if((s[c]=='?'||s[c]=='U')&&e(x-1, y)) {
        if(!(!e(x-2, y)&&e(x-1, y-1)&&e(x-1, y+1)))
        dfs(x-1, y, c+1);
    }
    if((s[c]=='?'||s[c]=='D')&&e(x+1, y)) {
        if(!(!e(x+2, y)&&e(x+1, y-1)&&e(x+1, y+1)))
        dfs(x+1, y, c+1);
    }

    vis[x][y]=0;
}
int main() {
    cin >> s;
    dfs(0, 0);
    cout << ans;
}
