#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=100;

string d;


// Brute Force - Accepted! O(n3)

// int main() {
//     cin >> d;
//     for(int i=0; i<d.size(); ++i) {
//         int a=d[i]-'0';
//         if(a%8==0) {
//             cout << "YES" <<endl << a;
//             return 0;
//         }
//         for(int j=i+1; j<d.size(); ++j) {
//             int b=a*10+(d[j]-'0');
//             if(b%8==0) {
//                 cout << "YES" <<endl << b;
//                 return 0;
//             }
//             for(int k=j+1; k<d.size(); ++k) {
//                 int c=b*10+(d[k]-'0');
//                 if(c%8==0) {
//                     cout << "YES" <<endl << c;
//                     return 0;
//                 }
//             }
//         }
//     }
//     cout << "NO";
// }

bool dp[mxN][8];
int p[mxN][8];
int main() {
    cin >> d;
    int n=d.size();
    for(int i=0; i<n; ++i) {
        dp[i][(d[i]-'0')%8]=1;
        p[i][(d[i]-'0')%8]=-1;
        if(i) {
            for(int j=0; j<8; ++j) {
                if(dp[i-1][j]) {
                    dp[i][j]=1;
                    p[i][j]=j;
                    dp[i][(j*10+(d[i]-'0'))%8]=1;
                    p[i][(j*10+(d[i]-'0'))%8]=j;
                }
            }
        }
    }

    if(dp[n-1][0]) {
        cout << "YES" << endl;
        vector<int> ans;
        int i=n-1, j=0;
        while(p[i][j]!=-1) {
            if(dp[i-1][j]!=1)
                j=p[i][j], ans.push_back(i);
            --i;
        }
        ans.push_back(i);
        reverse(ans.begin(), ans.end());
        for(int a : ans)
            cout << d[a];
    } else {
        cout << "NO" << endl;
    }

}
