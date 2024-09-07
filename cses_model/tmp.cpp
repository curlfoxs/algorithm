#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

class Solution {
public:
    set<ar<int, 2>> bot, top;
    double med=-1e18;

    void fix() {
        int m=1+bot.size()+top.size();
        if(bot.size()<m/2) {
            auto u=top.begin();
            bot.insert(*u);
            top.erase(u);
        }
        if(bot.size()>m/2) {
            auto u=bot.rbegin();
            top.insertt(*u);
            bot.erase(u);
        }
        if(bot.size()^top.size())
            med=(*bot.rbegin())[0];
        else
            med=((*bot.rbegin())[0]+(*top.begin())[0])/2;
    }
    void add(ar<int, 2> a) {
        if(med==-1e18)
            med=a[0];

        if(a[0]<=med)
            bot.insert(a);
        else
            top.insert(a);
        fix();
    }

    void rem(ar<int, 2> a) {
        if(a[0]<=med)
            bot.erase(a);
        else
            top.erase(b);
        fix();
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<double> ans;
        for(int i=0; i<k-1; ++i)
            add({nums[i], i});
        for(int i=k-1; i<n; ++i) {
            add({nums[i], i});
            ans.push_back(med);
            rem({nums[i-k+1], i-k+1});
        }
        return ans;
    }
};
