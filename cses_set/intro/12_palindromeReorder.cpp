#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mxN=1e6, M=1e9+7;

int c[26];

int main() {
    string s, s1, s2, s3;
    cin >> s;
    int r=0;
    for(char a : s) {
        c[a-'A']++;
        if(c[a-'A']&1)
            ++r;
        else
            --r;
    }

    if(r>1) {
        cout << "NO SOLUTION";
    }
    else {
        for(int i=0; i<26; ++i) {
            if(c[i]==0)
                continue;
            if(c[i]&1) {
                string s4(c[i], (char)('A'+i));
                s2=s4;
            }
            else {
                string s4(c[i]/2, (char)('A'+i));
                s1=s1+s4;
                s3=s4+s3;
            }
        }
        cout << s1+s2+s3;
    }
}
