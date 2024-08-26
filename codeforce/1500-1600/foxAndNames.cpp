#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e2;

bool vis[26], act[26];
string aut[mxN];
vector<int> adj[26], ans;

void dfs(int u) {
    vis[u]=1;
    act[u]=1;
    for(int v : adj[u]) {
        if(act[v]) {
            cout << "Impossible";
            exit(0);
        } else {
            if(!vis[v])
                dfs(v);
        }
    }
    act[u]=0;
    ans.push_back(u);
}
int main() {
    // 1. 处理输入
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        cin >> aut[i];
    }
    // 2. Build Graph 建图
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            int l=min(aut[i].length(), aut[j].length());
            int k;
            for(k=0; k<l; ++k) {
                if(aut[i][k]!=aut[j][k]) {
                    adj[aut[i][k]-'a'].push_back(aut[j][k]-'a');
                    break;
                }
            }
            if(k==l&&aut[i].length()>aut[j].length()) {
                cout << "Impossible";
                return 0;
            }
        }
    }

    // 3. 判断有向图是否成环，找到有效的拓扑排序
    for(int i=0; i<26; ++i)
        if(!vis[i])
            dfs(i);
    reverse(ans.begin(), ans.end());
    for(int a : ans)
        cout << (char)('a'+a);
}
