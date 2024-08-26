#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int f;
string b;

int main() {
    cin >> b;
    int n=b.size();
    for(int i=0; i<n; ++i) {
        if(b[i]=='0') {
            f=i;
            break;
        }
    }
    for(int i=0; i<n; ++i)
        if(i!=f)
            cout << b[i];
}
