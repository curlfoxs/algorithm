#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=100;

set<int> gp;
int n, x[mxN], sum, cnt;

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> x[i];
    sort(x, x+n);
    while(gp.size()!=n) {
        for(int i=0; i<n; ++i) {
            if(gp.find(i)==gp.end()&&sum<=x[i]) {
                if(sum==0) // first box in the pile
                    ++cnt;
                gp.insert(i);
                ++sum;
            }
        }
        sum=0;
    }
    cout << cnt;
}
