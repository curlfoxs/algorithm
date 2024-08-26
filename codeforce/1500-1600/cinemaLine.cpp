#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;

int n, b[mxN];

int main() {
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> b[i];

    int c25=0, c50=0;
    for(int i=0; i<n; ++i) {
        if(b[i]==25)
            ++c25;
        else if(b[i]==50) {
            if(c25) {
                ++c50;
                --c25;
            } else {
                cout << "NO";
                return 0;
            }
        }
        else {//100
            if(c50>=1&&c25>=1) {
                --c50, --c25;
            } else if(c25>=3) {
                c25-=3;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}
