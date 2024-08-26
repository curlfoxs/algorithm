#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e3, mxK=1e5, mxM=1e6, M=1e9+7;
int n, k;
string t, dic[mxK];
ll dp[mxN+1];

// Competitive programming trie implementation
struct {
    int c[mxM][26], rg=0;
    bool e[mxM];
    void ins(string s) {
        int u=0;
        for(char d : s) {
            if(!c[u][d-'a'])
                c[u][d-'a']=++rg;
            u=c[u][d-'a'];
        }
        e[u]=1;
    }
    int find(int x) {
        int u=0, ans=0;
        for(int i=x; i<n; ++i) {
            if(!c[u][t[i]-'a'])
                return ans;
            u=c[u][t[i]-'a'];
            if(e[u])
                ans=(ans+dp[i+1])%M;
        }
        return ans;
    }
    void tr() {};
} tr; // could not be delete?

int main() {
    cin >> t >> k;
    n=t.size();
    tr.tr();
    for(int i=0; i<k; ++i)
        cin >> dic[i], tr.ins(dic[i]);

    dp[n]=1;
    for(int i=n-1; i>=0; --i) {
        dp[i]=tr.find(i);
    }
    cout << dp[0];
}
