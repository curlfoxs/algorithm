#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array

const int mxN=2e4;

class Solution {
public:
    vector<int> adj[mxN], ans;
    multiset<int> rg[mxN];
    int mn=INT_MAX;
    void dfs1(int u=0, int p=-1) {
        for(int v : adj[u]) {
            if(p^u) {
                dfs1(v, u);
                rg[u].insert(*rg[v].rbegin()+1);
                while(rg[u].size()>2)
                    rg[u].erase(rg[u].begin());
            }
        }
        if(!rg[u].size())
            rg[u].insert(1);
    }

    void dfs2(int u=0, int p=-1) {
        if(~p) {
            if(*rg[u].rbegin()+1==*rg[p].rbegin()) {
                if(rg[p].size()==1)
                    rg[u].insert(1);
                else
                    rg[u].insert(*rg[p].begin()+1);
            } else {
                rg[u].insert(*rg[p].rbegin()+1);
            }
            while(rg[u].size()>2)
                rg[u].erase(rg[u].begin());
        }
        if(*rg[u].rbegin()<mn) {
            mn=*rg[u].begin();
            ans.clear();
            ans.push_back(u);
        } else if(*rg[u].rbegin()==mn)
            ans.push_back(u);
        for(int v : adj[u])
            if(v^p)
                dfs2(v, u);
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(int i=0; i<edges.size(); ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs1();
        dfs2();
        return ans;
    }
};
