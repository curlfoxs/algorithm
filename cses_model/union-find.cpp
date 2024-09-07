#include <bits/stdc++.h>
#define ar array
#define ll long long 
using namespace std;

// dp problem
const int mxN=50;

int rep[mxN];
    
int find(int x) {
    return x^rep[x]?rep[x]=find(rep[x]):x;
}

bool join(int x, int y) {
    if((x=find(x))==(y=find(y)))
        return 0;
    rep[x]=y;
    return 1;
}
