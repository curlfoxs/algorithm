#include <bits/stdc++.h>
#define ar array
#define ll long long 
using namespace std;

const int mxN=200;

#define ll long long 
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)
            return 0;
        ll dd=dividend, dr=divisor, ans=0;
        bool sn=(dd^dr)<0;
        dd=abs(dd);
        dr=abs(dr);
        for(int i=31; ~i; --i) {
            if((dd>>i)>=dr) {
                ans+=(ll)1<<i;
                dd-=dr<<i;
            }
        }
        ans=(sn)?-ans:ans;
        if(ans>(~(1<<31)))
            ans=(~(1<<31));
        if(ans<(1<<31))
            ans=1<<31;
        return ans;
    }
};
