#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=1e6;
// 错误的师范， 精度是不够的
// string ds;
// pair<double, int> stone[mxN];

// int main() {
//     cin >> ds;
//     int n=ds.size();
//     double s=0, t=((ll)1<<18);
//     for(int i=0; i<n; ++i) {
//         double mid=(s+t)/2;
//         stone[i].first=mid;
//         stone[i].second=i;
//         if(ds[i]=='l')
//             t=mid;
//         else
//             s=mid;
//     }
//     sort(stone, stone+n );
//     for(int i=0; i<n; ++i)
//         cout << stone[i].second+1 << endl;
// }


string ds;
int a[mxN];

int main() {
    cin >> ds;
    int n=ds.size();
    int lp=0, rp=n-1;
    for(int i=0; i<n; ++i) {
        if(ds[i]=='l')
            a[rp--]=i;
        else
            a[lp++]=i;
    }
    for(int i=0; i<n; ++i)
        cout << a[i]+1 << endl;
}
