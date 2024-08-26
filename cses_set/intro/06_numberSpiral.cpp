#include <bits/stdc++.h>

using namespace std;



int main() {
    int n;
    cin >> n;
    while(n--) {
        long long  x, y;
        cin >> y >> x;
        long long mx=max(y, x);
        // max of row and column is even
        if(mx%2==0) {
            if(mx==y) { // row > column
                cout << mx*mx-(x-1) << endl;
            } else { // column > row
                cout << (mx-1)*(mx-1)+y << endl;
            }
        }
        // max of row and column is odd
        else {
            if(mx==x) {
                cout << mx*mx-(y-1) << endl;
            } else {
                cout << (mx-1)*(mx-1)+x << endl;
            }
        }
    }
}
