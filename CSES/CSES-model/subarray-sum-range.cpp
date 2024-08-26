#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ar array

const int mxN=1e5;

int n;
class Solution {
public:
    ll seg[4*mxN];
    void upd(int p, int x, int i=0, int l=0, int r=n) {
        if(p>r || p<l)
            return;
        if(l==r&&p<=l&&p>=r) {
            seg[i]+=x;
            return;
        }
        int mid=(l+r)/2;
        upd(p, x, 2*i+1, l, mid);
        upd(p, x, 2*i+2, mid+1, r);
        seg[i]=seg[2*i+1]+seg[2*i+2];

    }
    ll qry(int lb, int rb, int i=0, int l=0, int r=n) {
        if(lb>r||rb<l)
            return 0;
        if(lb<=l&&rb>=r)
            return seg[i];
        int mid=(l+r)/2;
        return qry(lb, rb, 2*i+1, l, mid)+qry(lb, rb, 2*i+2, mid+1, r);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        memset(seg, 0, sizeof(seg));
        n=nums.size();
        int ans=0;
        vector<ll> pre(n+1);
        pre[0]=0;
        for(int i=0; i<n; ++i)
            pre[i+1]=pre[i]+nums[i];
        vector<ll> cp(pre.begin(), pre.end());
        sort(cp.begin(), cp.end());
        for(int i=n; i>=0; --i) {
            int l=lower_bound(cp.begin(), cp.end(), lower+pre[i])-cp.begin();
            int r=upper_bound(cp.begin(), cp.end(), upper+pre[i])-cp.begin()-1;
            int p=lower_bound(cp.begin(), cp.end(), pre[i])-cp.begin();
            ans+=qry(l, r);
            upd(p, 1);
        }
        return ans;
    }
};
