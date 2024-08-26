#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ar array

const int mxN=1e2;

int a[mxN];
void divide(int a, int b) {
    string s, ans;
    int q=a/b;
    int rm=a%b;
    s+=to_string(q)+".";
    while(rm&&s.size()<=8) {
        rm*=10;
        q=rm/b;
        rm%=b;
        s+=to_string(q);
    }
    while(s.size()<8)
        s+="0";
    if(s.size()>8) {
        int tail=s.back()-'0';
        s.pop_back();
        int cf=(tail>=5)?1:0;
        int i=s.size()-1;
        while(i>=2||cf) {
            if(i>=2)
                cf+=s[i]-'0';
            ans+=(char)(cf%10+'0');
            cf/=10;
            --i;
        }
        ans+=(cf)?".1":".0";
        reverse(ans.begin(), ans.end());
        s=ans;
    }
    cout << s << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    int c1=0, c2=0, c3=0;
    for(int i=0; i<n; ++i) {
        if(a[i]>0)
            c1++;
        else if(a[i]==0)
            c3++;
        else
            c2++;
    }
    divide(c1, n);
    divide(c2, n);
    divide(c3, n);
}
