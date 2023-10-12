#include <bits/stdc++.h>
#define ar array
#define ll long long 
using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string ans;
        if((numerator^denominator)<0) ans+="-";
        ll dt=abs(numerator), dr=abs(denominator);
        ll q=dt/dr, rm=dt%dr;
        ans+=to_string(q);
        if(rm) ans+=".";
        string de;
        unordered_map<int, int> mp;
        int cyc=-1;
        while(rm) {
            mp[rm]=de.size();
            rm*=10;
            q=rm/dr;
            de+=to_string(q);
            rm=rm%dr;
            if(mp.find(rm)!=mp.end()){
                cyc=mp[rm];
                break;
            }
        }
        if(!rm) {
            ans+=de;
            return ans;
        }
        if(~cyc) {
            de.insert(cyc, "(");
            de+=')';
            ans+=de;
        }
        return ans;
    }
};
