#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxM=5e5;

int n, k, mn;
string s;
int main() {
    cin >> n >> k >> s;
    if(k==2) {
        // ABABA...
        int c1=0, c2=0;
        string s1(n, 'A');
        for(int i=1; i<n; i+=2)
            s1[i]='B';
        for(int i=0; i<n; ++i)
            if(s[i]!=s1[i])
                ++c1;
        // BABAA...
        string s2(n, 'B');
        for(int i=1; i<n; i+=2)
            s2[i]='A';
        for(int i=0; i<n; ++i)
            if(s[i]!=s2[i])
                ++c2;
        if(c1<c2) {
            cout << c1 << endl << s1;
        } else {
            cout << c2 << endl << s2;
        }
        return 0;
    }

    int c=0;
    for(int i=1; i<n; ++i) {
        if(s[i]==s[i-1]) {
            int yu=((s[i-1]-'A')%3+1)%3;
            if(i<n-1&&((s[i+1]-'A')%3==yu))
                yu=(yu+1)%3;
            s[i]=(char)('A'+yu);
            ++c;
        }
    }
    cout << c << endl << s;
}
