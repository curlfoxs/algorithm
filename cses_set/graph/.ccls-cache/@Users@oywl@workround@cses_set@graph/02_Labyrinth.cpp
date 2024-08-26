#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e3;


int n, m, si, sj, ti, tj, di[4]={-1, 1, 0, 0}, dj[4]={0, 0, -1, 1};
int p[mxN][mxN];
char dc[4]={'U', 'D', 'L', 'R'};
string mt[mxN];

bool e(int i, int j) {
    return i>=0&&i<n&&j>=0&&j<m&&mt[i][j]=='.';
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; ++i) {
        cin >> mt[i];
        for(int j=0; j<m; ++j) {
            if(mt[i][j]=='A')
                si=i, sj=j, mt[i][j]='#';
            if(mt[i][j]=='B')
                ti=i, tj=j, mt[i][j]='.';
        }
    }

    bool ok=0;
    queue<array<int, 2>> qu;
    qu.push({si, sj});
    while(qu.size()) {
        ar<int, 2> u=qu.front();
        qu.pop();
        if(u[0]==ti&&u[1]==tj) {
            ok=1;
            break;
        }
        for(int k=0; k<4; ++k) {
            int ni=u[0]+di[k], nj=u[1]+dj[k];
            if(!e(ni, nj))
                continue;
            mt[ni][nj]='#';
            p[ni][nj]=k;
            qu.push({ni, nj});
        }
}
    if(!ok) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    string ans;
    while(!(si==ti&&sj==tj)) {
        int k=p[ti][tj];
        ans+=dc[k];
        int pi=ti-di[k], pj=tj-dj[k];
        ti=pi, tj=pj;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl << ans;
}
