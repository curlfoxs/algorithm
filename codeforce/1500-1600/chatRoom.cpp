#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define ar array

const int mxN=100;

string s;

int main() {
    cin >> s;
    int n=s.size(), p=0;
    string t="hello";
    for(int i=0; i<n; ++i) {
        if(s[i]==t[p])
            ++p;
        if(p==t.size()) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
