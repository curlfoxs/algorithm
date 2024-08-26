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

const int mxN=5e3, mxK=1e5, mxM=1e6, M=1e9+7;
int n, k, dp[mxN+1];
string s, t;

struct {
    int child[mxM][26], go[mxM][26], ol[mxM], fl[mxM], rg=0, d[mxM];
    void ins(string s) {
        int u=0;
        for(char ch : s) {
            if(!child[u][ch-'a'])
                child[u][ch-'a']=++rg;
            u=child[u][ch-'a'];
        }
        ol[u]=u;
    }
    void ac() {
        queue<int> qu;
        qu.push(0);
        while(qu.size()) {
            int u=qu.front();
            qu.pop();
            // cout << "U: " << u << endl;
            for(int i=0; i<26; ++i) {
                if(child[u][i]) {
                    int v=child[u][i];
                    d[v]=d[u]+1; // Record distance
                    fl[v]=go[fl[u]][i]; // Go the Nearst faliure link of BFS to fill child faillure link
                    if(!ol[v])
                        ol[v]=ol[fl[v]]; // Build output link
                    go[u][i]=v; // If match transaction to the child link
                    qu.push(v);
                } else {
                    go[u][i]=go[fl[u]][i]; // If match faliure  transaction to the failiure link
                }
            }
        }
    } 
} ac;

int main() {
    cin >> t >> k, n=t.size();
    for(int i=0; i<k; ++i) {
        cin >> s;
        ac.ins(s);
    }

    dp[0]=1;
    ac.ac();
    int u=0;
    for(int i=1; i<=n; ++i) {
        u=ac.go[u][t[i-1]-'a'];
        // cout << u << endl;
        int v=ac.ol[u];
        while(v) {
            // cout << v << endl;
            dp[i]=(dp[i]+dp[i-ac.d[v]])%M;
            v=ac.ol[ac.fl[v]];
        }
    }
    cout << dp[n];
}




